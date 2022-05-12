use neon::prelude::*;

fn to_i32<'a>(
    cx: &mut FunctionContext<'a>,
    value: Handle<JsValue>,
) -> Result<i32, JsResult<'a, JsNumber>> {
    let value = value.downcast_or_throw::<JsNumber, _>(cx).map_err(Err)?.value(cx);

    if value.is_infinite() || value.is_nan() || value.fract() > f64::EPSILON {
        return Err(cx.throw_type_error(format!("{} is not an integer", value)));
    }

    let value = value as i64;

    // use `u32` here to check because the input may be in **0b**, **0o** or **0x** formats, which may be bigger than **2^31 - 1** but smaller than **2^32 - 1** and therefore is negative in i32
    if value > u32::MAX as i64 {
        Err(cx.throw_range_error(format!("{} is bigger than {}", value, u32::MAX)))
    } else if value < i32::MIN as i64 {
        Err(cx.throw_range_error(format!("{} is smaller than {}", value, i32::MIN)))
    } else {
        Ok(value as i32)
    }
}

fn to_js_number<'a>(cx: &mut FunctionContext<'a>, i: i32) -> JsResult<'a, JsNumber> {
    Ok(JsNumber::new(cx, i as f64))
}

#[inline]
fn js_number_0<'a>(cx: &mut FunctionContext<'a>) -> JsResult<'a, JsNumber> {
    Ok(JsNumber::new(cx, 0))
}

fn parse_arguments<'a>(cx: &mut FunctionContext<'a>) -> Result<(i32, i32), JsResult<'a, JsNumber>> {
    match cx.argument_opt(0) {
        Some(arg1) => {
            let arg1 = match to_i32(cx, arg1) {
                Ok(arg) => arg,
                Err(err) => return Err(err),
            };

            match cx.argument_opt(1) {
                Some(arg2) => {
                    let arg2 = match to_i32(cx, arg2) {
                        Ok(arg) => arg,
                        Err(err) => return Err(err),
                    };

                    Ok((arg1, arg2))
                }
                None => Err(to_js_number(cx, arg1)),
            }
        }
        None => Err(js_number_0(cx)),
    }
}

fn add(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    let sum = arg1.wrapping_add(arg2);

    to_js_number(&mut cx, sum)
}

fn subtract(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    let difference = arg1.wrapping_sub(arg2);

    to_js_number(&mut cx, difference)
}

fn multiply(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    let product = arg1.wrapping_mul(arg2);

    to_js_number(&mut cx, product)
}

fn divide(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    let quotient = arg1.wrapping_div(arg2);

    to_js_number(&mut cx, quotient)
}

fn pow(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx
            .throw_range_error("the exponent of an integer number may not be smaller than zero");
    }

    let product = arg1.wrapping_pow(arg2 as u32);

    to_js_number(&mut cx, product)
}

fn shift_left(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx.throw_range_error("the bit count for shift may not be smaller than zero");
    }

    let c = arg1.wrapping_shl(arg2 as u32);

    to_js_number(&mut cx, c)
}

fn shift_right(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx.throw_range_error("the bit count for shift may not be smaller than zero");
    }

    let c = arg1.wrapping_shr(arg2 as u32);

    to_js_number(&mut cx, c)
}

fn shift_right_unsigned(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx.throw_range_error("the bit count for shift may not be smaller than zero");
    }

    let c = (arg1 as u32).wrapping_shr(arg2 as u32);

    to_js_number(&mut cx, c as i32)
}

fn rotate_left(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx.throw_range_error("the bit count for rotation may not be smaller than zero");
    }

    let c = arg1.rotate_left(arg2 as u32);

    to_js_number(&mut cx, c)
}

fn rotate_right(mut cx: FunctionContext) -> JsResult<JsNumber> {
    let (arg1, arg2) = match parse_arguments(&mut cx) {
        Ok(args) => args,
        Err(err) => return err,
    };

    if arg2 < 0 {
        return cx.throw_range_error("the bit count for rotation may not be smaller than zero");
    }

    let c = arg1.rotate_right(arg2 as u32);

    to_js_number(&mut cx, c)
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
