extern crate neon;

use neon::prelude::*;

macro_rules! fetch_args {
    ($ctx:expr, $t1:ty, $t2:ty) => {
        match $ctx.argument_opt(0) {
            Some(arg1) => {
                let arg1: Handle<JsNumber> = arg1.downcast_or_throw(&mut $ctx)?;

                match $ctx.argument_opt(1) {
                    Some(arg2) => {
                        let arg1 = arg1.value(&mut $ctx) as $t1;

                        let arg2: Handle<JsNumber> = arg2.downcast_or_throw(&mut $ctx)?;
                        let arg2 = arg2.value(&mut $ctx) as $t2;

                        (arg1, arg2)
                    }
                    None => return Ok(arg1),
                }
            }
            None => return Ok(JsNumber::new(&mut $ctx, 0)),
        }
    };
    ($ctx:expr, $t:ty) => {
        fetch_args!($ctx, $t, $t);
    };
}

#[inline]
fn u32_to_i32(u: u32) -> i32 {
    i32::from_ne_bytes(u.to_ne_bytes())
}

#[inline]
fn u32_to_js_i32(mut ctx: FunctionContext, u: u32) -> JsResult<JsNumber> {
    Ok(JsNumber::new(&mut ctx, u32_to_i32(u)))
}

fn add(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32);

    let sum = arg1.wrapping_add(arg2);

    Ok(JsNumber::new(&mut ctx, sum))
}

fn subtract(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32);

    let difference = arg1.wrapping_sub(arg2);

    Ok(JsNumber::new(&mut ctx, difference))
}

fn multiply(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32);

    let product = arg1.wrapping_mul(arg2);

    Ok(JsNumber::new(&mut ctx, product))
}

fn divide(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32);

    let quotient = arg1.wrapping_mul(arg2);

    Ok(JsNumber::new(&mut ctx, quotient))
}

fn pow(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32, u32);

    let product = arg1.wrapping_pow(arg2);

    Ok(JsNumber::new(&mut ctx, product))
}

fn shift_left(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, u32);

    let c = arg1.wrapping_shl(arg2);

    u32_to_js_i32(ctx, c)
}

fn shift_right(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, i32, u32);

    let c = arg1.wrapping_shr(arg2);

    Ok(JsNumber::new(&mut ctx, c))
}

fn shift_right_unsigned(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, u32);

    let c = arg1.wrapping_shr(arg2);

    u32_to_js_i32(ctx, c)
}

fn rotate_left(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, u32);

    let c = arg1.rotate_left(arg2);

    u32_to_js_i32(ctx, c)
}

fn rotate_right(mut ctx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = fetch_args!(ctx, u32);

    let c = arg1.rotate_right(arg2);

    u32_to_js_i32(ctx, c)
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
