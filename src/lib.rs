use napi::bindgen_prelude::*;
use napi_derive::napi;

/// Computes `a + b`, wrapping around at the boundary of an 32-bit integer.
#[napi]
pub fn add(a: i32, b: i32) -> i32 {
    a.wrapping_add(b)
}

/// Computes `a - b`, wrapping around at the boundary of an 32-bit integer.
#[napi]
pub fn subtract(a: i32, b: i32) -> i32 {
    a.wrapping_sub(b)
}

/// Computes `a * b`, wrapping around at the boundary of an 32-bit integer.
#[napi]
pub fn multiply(a: i32, b: i32) -> i32 {
    a.wrapping_mul(b)
}

/// Computes `a / b`, wrapping around at the boundary of an 32-bit integer.
#[napi]
pub fn divide(a: i32, b: i32) -> i32 {
    a.wrapping_div(b)
}

/// Computes `a ^ b`, wrapping around at the boundary of an 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi]
pub fn pow(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error(
            "the exponent of an integer number must not be smaller than zero",
            None,
        )?;

        return Err(Error::from_reason(""));
    }

    Ok(a.wrapping_pow(b as u32))
}

/// Computes `a << b`, wrapping around at the boundary of an 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi(js_name = "shiftLeft")]
pub fn shift_left(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error("the bit count for shift must not be smaller than zero", None)?;

        return Err(Error::from_reason(""));
    }

    Ok(a.wrapping_shl(b as u32))
}

/// Computes `a >> b`, wrapping around at the boundary of an 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi(js_name = "shiftRight")]
pub fn shift_right(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error("the bit count for shift must not be smaller than zero", None)?;

        return Err(Error::from_reason(""));
    }

    Ok(a.wrapping_shr(b as u32))
}

/// Computes `a >>> b`, wrapping around at the boundary of an 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi(js_name = "shiftRightUnsigned")]
pub fn shift_right_unsigned(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error("the bit count for shift must not be smaller than zero", None)?;

        return Err(Error::from_reason(""));
    }

    Ok((a as u32).wrapping_shr(b as u32) as i32)
}

/// Shifts the bits to the right by a specified amount n, wrapping the truncated bits to the beginning of the resulting 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi(js_name = "rotateLeft")]
pub fn rotate_left(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error("the bit count for rotation must not be smaller than zero", None)?;

        return Err(Error::from_reason(""));
    }

    Ok(a.rotate_left(b as u32))
}

/// Shifts the bits to the right by a specified amount n, wrapping the truncated bits to the beginning of the resulting 32-bit integer.
///
/// `b` must not be smaller than zero
#[napi(js_name = "rotateRight")]
pub fn rotate_right(env: Env, a: i32, b: i32) -> Result<i32> {
    if b < 0 {
        env.throw_range_error("the bit count for rotation must not be smaller than zero", None)?;

        return Err(Error::from_reason(""));
    }

    Ok(a.rotate_right(b as u32))
}
