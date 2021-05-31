extern crate neon;

use neon::prelude::*;

macro_rules! fetch_args {
    ($cx:expr, $t1:ty, $t2:ty) => {
        match $cx.argument_opt(0) {
            Some(arg1) => {
                let arg1 = arg1.downcast_or_throw::<JsNumber, _>(&mut $cx)?;

                match $cx.argument_opt(1) {
                    Some(arg2) => {
                        let arg1 = arg1.value(&mut $cx) as $t1;

                        let arg2 = arg2.downcast_or_throw::<JsNumber, _>(&mut $cx)?;
                        let arg2 = arg2.value(&mut $cx) as $t2;

                        (arg1, arg2)
                    }
                    None => return Ok(arg1),
                }
            }
            None => return Ok(JsNumber::new(&mut $cx, 0)),
        }
    };
    ($cx:expr, $t:ty) => {
        fetch_args!($cx, $t, $t);
    };
}

#[inline]
fn u32_to_i32(u: u32) -> i32 {
    i32::from_ne_bytes(u.to_ne_bytes())
}

#[inline]
fn u32_to_js_i32(mut cx: FunctionContext, u: u32) -> JsResult<JsNumber> {
    Ok(JsNumber::new(&mut cx, u32_to_i32(u)))
}

fn add(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32);

    let sum = arg1.wrapping_add(arg2);

    Ok(JsNumber::new(&mut cx, sum))
}

fn subtract(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32);

    let difference = arg1.wrapping_sub(arg2);

    Ok(JsNumber::new(&mut cx, difference))
}

fn multiply(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32);

    let product = arg1.wrapping_mul(arg2);

    Ok(JsNumber::new(&mut cx, product))
}

fn divide(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32);

    let quotient = arg1.wrapping_mul(arg2);

    Ok(JsNumber::new(&mut cx, quotient))
}

fn pow(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32, u32);

    let product = arg1.wrapping_pow(arg2);

    Ok(JsNumber::new(&mut cx, product))
}

fn shift_left(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, u32);

    let c = arg1.wrapping_shl(arg2);

    u32_to_js_i32(cx, c)
}

fn shift_right(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, i32, u32);

    let c = arg1.wrapping_shr(arg2);

    Ok(JsNumber::new(&mut cx, c))
}

fn shift_right_unsigned(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, u32);

    let c = arg1.wrapping_shr(arg2);

    u32_to_js_i32(cx, c)
}

fn rotate_left(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, u32);

    let c = arg1.rotate_left(arg2);

    u32_to_js_i32(cx, c)
}

fn rotate_right(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(cx, u32);

    let c = arg1.rotate_right(arg2);

    u32_to_js_i32(cx, c)
}

#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("add", add)?;
    cx.export_function("subtract", subtract)?;
    cx.export_function("multiply", multiply)?;
    cx.export_function("divide", divide)?;
    cx.export_function("pow", pow)?;
    cx.export_function("shiftLeft", shift_left)?;
    cx.export_function("shiftRight", shift_right)?;
    cx.export_function("shiftRightUnsigned", shift_right_unsigned)?;
    cx.export_function("rotateLeft", rotate_left)?;
    cx.export_function("rotateRight", rotate_right)?;

    Ok(())
}
