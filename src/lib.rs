use napi::bindgen_prelude::*;
use napi_derive::napi;

#[napi]
pub fn add(a: i32, b: i32) -> i32 {
    a.wrapping_add(b)
}

#[napi]
pub fn subtract(a: i32, b: i32) -> i32 {
    a.wrapping_sub(b)
}

#[napi]
pub fn multiply(a: i32, b: i32) -> i32 {
    a.wrapping_mul(b)
}

#[napi]
pub fn divide(a: i32, b: i32) -> i32 {
    a.wrapping_div(b)
}

#[napi]
pub fn pow(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the exponent of an integer number must not be smaller than zero"));
    }

    Ok(a.wrapping_pow(b as u32))
}

#[napi(js_name = "shiftLeft")]
pub fn shift_left(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the bit count for shift must not be smaller than zero"));
    }

    Ok(a.wrapping_shl(b as u32))
}

#[napi(js_name = "shiftRight")]
pub fn shift_right(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the bit count for shift must not be smaller than zero"));
    }

    Ok(a.wrapping_shr(b as u32))
}

#[napi(js_name = "shiftRightUnsigned")]
pub fn shift_right_unsigned(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the bit count for shift must not be smaller than zero"));
    }

    Ok((a as u32).wrapping_shr(b as u32) as i32)
}

#[napi(js_name = "rotateLeft")]
pub fn rotate_left(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the bit count for rotation must not be smaller than zero"));
    }

    Ok(a.rotate_left(b as u32))
}

#[napi(js_name = "rotateRight")]
pub fn rotate_right(a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        return Err(Error::from_reason("the bit count for rotation must not be smaller than zero"));
    }

    Ok(a.rotate_right(b as u32))
}
