#include <node_api.h>
#include <stdlib.h>

napi_value createFalse(napi_env env){
    napi_value result;
    napi_create_number(env, 0, &result);
    napi_coerce_to_bool(env, result, &result);
    return result;
}

napi_value add(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_number(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                double d = (a + b);

                napi_create_number(env, d, &result);
        }

        return result;
}

napi_value subtract(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_number(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                double d = (a - b);

                napi_create_number(env, d, &result);
        }

        return result;
}

napi_value multiply(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_number(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                double d = (a * b);

                napi_create_number(env, d, &result);
        }

        return result;
}

napi_value divide(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_number(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                double d = (a / b);
                napi_create_number(env, d, &result);
        }

        return result;
}

napi_value operate(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_number(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t initialValue;
                uint32_t operationLength;
                napi_get_value_int32(env, args[0], &initialValue);
                napi_get_array_length(env, args[1], &operationLength);
                int32_t number = initialValue;
                uint32_t i = 0;
                for(; i<operationLength; ++i) {
                        size_t aLength;
                        napi_value operation;
                        napi_get_element(env, args[1], i, &operation);
                        napi_get_value_string_utf8(env, operation, NULL, 0, &aLength);
                        char a[aLength + 1];
                        napi_get_value_string_utf8(env, operation, a, aLength + 1, 0);
                        if(aLength < 2){
                            return createFalse(env);
                        }
                        char operator = a[0];
                        int32_t value = (int32_t)atof(a + 1);
                        switch(operator){
                            case '+':
                                number += value;
                                break;
                            case '-':
                                number -= value;
                                break;
                            case '*':
                                number *= value;
                                break;
                            case '/':
                                number /= value;
                                break;
                            default:
                                return createFalse(env);
                        }
                }
                napi_create_number(env, number, &result);
        }

        return result;
}

void Init (napi_env env, napi_value exports, napi_value module, void* priv) {
        napi_property_descriptor allDesc[] = {
                {"add", 0, add, 0, 0, 0, napi_default, 0},
                {"subtract", 0, subtract, 0, 0, 0, napi_default, 0},
                {"multiply", 0, multiply, 0, 0, 0, napi_default, 0},
                {"divide", 0, divide, 0, 0, 0, napi_default, 0},
                {"operate", 0, operate, 0, 0, 0, napi_default, 0}
        };
        napi_define_properties(env, exports, 5, allDesc);
}

NAPI_MODULE(int32, Init);
