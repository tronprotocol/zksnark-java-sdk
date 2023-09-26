use std::slice;

use libc::c_uchar;

mod bn254;
mod serialize;

pub const FIELD_ELEMENT_SIZE: usize = 32;
pub const G1_SERIALIZED_SIZE: usize = 64;
pub const G2_SERIALIZED_SIZE: usize = 128;

#[no_mangle]
pub extern "system" fn libarkworks_g1_is_valid(
    x: *const [c_uchar; FIELD_ELEMENT_SIZE],
    y: *const [c_uchar; FIELD_ELEMENT_SIZE],
) -> bool {
    let x = unsafe { &*x };
    let y = unsafe { &*y };
    bn254::g1_is_valid([&x[..], y].concat())
}

#[no_mangle]
pub extern "system" fn libarkworks_g2_is_valid(
    a: *const [c_uchar; FIELD_ELEMENT_SIZE],
    b: *const [c_uchar; FIELD_ELEMENT_SIZE],
    c: *const [c_uchar; FIELD_ELEMENT_SIZE],
    d: *const [c_uchar; FIELD_ELEMENT_SIZE],
) -> bool {
    let a = unsafe { &*a };
    let b = unsafe { &*b };
    let c = unsafe { &*c };
    let d = unsafe { &*d };
    bn254::g2_is_valid([&a[..], b, c, d].concat())
}

#[no_mangle]
pub extern "system" fn libarkworks_add_g1(
    a: *const [c_uchar; G1_SERIALIZED_SIZE],
    b: *const [c_uchar; G1_SERIALIZED_SIZE],
    result: *mut [c_uchar; G1_SERIALIZED_SIZE],
) -> bool {
    let a_serialized = unsafe { &*a };
    let b_serialized = unsafe { &*b };
    let result = unsafe { &mut *result };

    match bn254::add_g1(a_serialized, b_serialized) {
        Ok(sum) => {
            result.copy_from_slice(&sum);
            true
        }
        Err(_) => false,
    }
}

#[no_mangle]
pub extern "system" fn libarkworks_mul_g1(
    p: *const [c_uchar; G1_SERIALIZED_SIZE],
    s: *const [c_uchar; FIELD_ELEMENT_SIZE],
    result: *mut [c_uchar; G1_SERIALIZED_SIZE],
) -> bool {
    let p_serialized = unsafe { &*p };
    let s_serialized = unsafe { &*s };
    let result = unsafe { &mut *result };

    match bn254::mul_g1(p_serialized, s_serialized) {
        Ok(product) => {
            result.copy_from_slice(&product);
            true
        }
        Err(_) => false,
    }
}

#[no_mangle]
pub extern "system" fn libarkworks_pairing_check(
    g1s: *const c_uchar,
    g2s: *const c_uchar,
    pairs: u32,
) -> bool {
    let g1s_serialized = unsafe { slice::from_raw_parts(g1s, G1_SERIALIZED_SIZE * pairs as usize) };
    let g2s_serialized = unsafe { slice::from_raw_parts(g2s, G2_SERIALIZED_SIZE * pairs as usize) };

    bn254::pairing_check(g1s_serialized, g2s_serialized, pairs as usize).unwrap_or(false)
}

#[no_mangle]
pub extern "system" fn libarkworks_random_g1(result: *mut [c_uchar; G1_SERIALIZED_SIZE]) {
    let result = unsafe { &mut *result };
    result.copy_from_slice(&bn254::random_g1());
}

#[no_mangle]
pub extern "system" fn libarkworks_random_g2(result: *mut [c_uchar; G2_SERIALIZED_SIZE]) {
    let result = unsafe { &mut *result };
    result.copy_from_slice(&bn254::random_g2());
}
