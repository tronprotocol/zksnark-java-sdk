use ark_bn254::{Bn254, G1Affine, G2Affine};
use ark_ec::{pairing::Pairing, AffineRepr, CurveGroup};
use ark_ff::{BigInteger256, Field, Fp12, UniformRand};
use ark_serialize::SerializationError;

use crate::{serialize::EthSerializeDeserialize, G1_SERIALIZED_SIZE, G2_SERIALIZED_SIZE};

pub fn random_g1() -> Vec<u8> {
    let mut rng = rand::thread_rng();
    G1Affine::rand(&mut rng)
        .eth_serialize()
        .expect("failed to serialize random point")
}

pub fn random_g2() -> Vec<u8> {
    let mut rng = rand::thread_rng();
    G2Affine::rand(&mut rng)
        .eth_serialize()
        .expect("failed to serialize random point")
}

pub fn g1_is_valid(serialized: Vec<u8>) -> bool {
    // We probably can safely bypass is_in_correct_subgroup_assuming_on_curve check
    // since there is only one subgroup and we can't fail this check
    let g1 = G1Affine::eth_deserialize_unchecked(&serialized);
    match g1 {
        Ok(g1) => g1.is_on_curve(),
        Err(_) => false,
    }
}

pub fn g2_is_valid(serialized: Vec<u8>) -> bool {
    G2Affine::eth_deserialize(&serialized).is_ok()
}

pub fn add_g1(a_serialized: &[u8], b_serialized: &[u8]) -> Result<Vec<u8>, SerializationError> {
    let a = G1Affine::eth_deserialize_unchecked(a_serialized)?;
    let b = G1Affine::eth_deserialize_unchecked(b_serialized)?;
    (a + b).into_affine().eth_serialize()
}

pub fn mul_g1(a_serialized: &[u8], s_serialized: &[u8]) -> Result<Vec<u8>, SerializationError> {
    let p = G1Affine::eth_deserialize_unchecked(a_serialized)?;
    let s = BigInteger256::eth_deserialize(s_serialized)?;
    p.mul_bigint(s).into_affine().eth_serialize()
}

pub fn pairing_check(
    g1s_serialized: &[u8],
    g2s_serialized: &[u8],
    pairs: usize,
) -> Result<bool, SerializationError> {
    let mut g1s = vec![];
    let mut g2s = vec![];
    for i in 0..pairs {
        g1s.push(G1Affine::eth_deserialize_unchecked(
            &g1s_serialized[i * G1_SERIALIZED_SIZE..(i + 1) * G1_SERIALIZED_SIZE],
        )?);
        g2s.push(G2Affine::eth_deserialize_unchecked(
            &g2s_serialized[i * G2_SERIALIZED_SIZE..(i + 1) * G2_SERIALIZED_SIZE],
        )?);
    }

    let result = Bn254::multi_pairing(g1s, g2s);
    Ok(result.0 == Fp12::ONE)
}
