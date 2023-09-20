use ark_ec::short_weierstrass::{Affine, SWCurveConfig};
use ark_ff::BigInteger256;
use ark_serialize::{CanonicalDeserialize, CanonicalSerialize, Compress, SerializationError};

use crate::FIELD_ELEMENT_SIZE;

pub trait EthSerializeDeserialize {
    fn eth_serialize(&self) -> Result<Vec<u8>, SerializationError>;

    fn eth_deserialize(serialized: &[u8]) -> Result<Self, SerializationError>
    where
        Self: Sized;

    fn eth_deserialize_unchecked(serialized: &[u8]) -> Result<Self, SerializationError>
    where
        Self: Sized;
}

impl<P: SWCurveConfig> EthSerializeDeserialize for Affine<P> {
    fn eth_serialize(&self) -> Result<Vec<u8>, SerializationError> {
        if self.infinity {
            // infinity encoded as (0, 0)
            return Ok(vec![0; self.serialized_size(Compress::No)]);
        }

        let mut serialized = vec![];
        self.serialize_with_mode(&mut serialized, Compress::No)?;
        clear_flags(&mut serialized);
        Ok(convert_to_big_endian(&serialized))
    }

    fn eth_deserialize(serialized: &[u8]) -> Result<Self, SerializationError> {
        if is_zero_vec(serialized) {
            return Ok(Affine::identity());
        }
        let serialized = convert_to_little_endian(serialized);
        Self::deserialize_uncompressed(&serialized[..])
    }

    fn eth_deserialize_unchecked(serialized: &[u8]) -> Result<Self, SerializationError> {
        if is_zero_vec(serialized) {
            return Ok(Affine::identity());
        }
        let serialized = convert_to_little_endian(serialized);
        Self::deserialize_uncompressed_unchecked(&serialized[..])
    }
}

impl EthSerializeDeserialize for BigInteger256 {
    fn eth_serialize(&self) -> Result<Vec<u8>, SerializationError> {
        let mut serialized = vec![];
        self.serialize_with_mode(&mut serialized, Compress::No)?;
        Ok(convert_to_big_endian(&serialized))
    }

    fn eth_deserialize(serialized: &[u8]) -> Result<Self, SerializationError> {
        let serialized = convert_to_little_endian(serialized);
        Self::deserialize_uncompressed(&serialized[..])
    }

    fn eth_deserialize_unchecked(serialized: &[u8]) -> Result<Self, SerializationError> {
        Self::eth_deserialize(serialized)
    }
}

fn clear_flags(serialized: &mut Vec<u8>) {
    // we can clear flags since it is possible to
    // restore points without them
    let last = serialized.len() - 1;
    serialized[last] &= 0b00111111;
}

fn is_zero_vec(vec: &[u8]) -> bool {
    vec.iter().all(|b| *b == 0)
}

fn convert_to_little_endian(serialized: &[u8]) -> Vec<u8> {
    convert_to_big_endian(serialized)
}

fn convert_to_big_endian(serialized: &[u8]) -> Vec<u8> {
    serialized
        .chunks(FIELD_ELEMENT_SIZE)
        .map(|chunk| {
            let mut chunk = Vec::from(chunk);
            chunk.reverse();
            chunk
        })
        .fold(vec![], |mut acc, chunk| {
            acc.extend(chunk);
            acc
        })
}
