#include <node_api.h>
#include <stdlib.h>

napi_ref Int32Ref;

// TODO -----Creators-----

napi_value createFalse(napi_env env){
        napi_value result;
        napi_get_boolean(env, false, &result);
        return result;
}

// TODO -----Static-----

napi_value from(napi_env env, napi_callback_info info){
        napi_value me, newMe;
        size_t argsLength = 1;
        napi_value args[1];
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);

        napi_value Int32;
        napi_get_reference_value(env, Int32Ref, &Int32);

        napi_new_instance(env, Int32, argsLength, args, &newMe);
        return newMe;
}

napi_value add(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a + b);

                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value subtract(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a - b);

                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value multiply(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a * b);

                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value divide(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a / b);
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value shiftLeft(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a << b);
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value shiftRight(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (a >> b);
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value shiftRightUnsigned(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (int32_t)((uint32_t)a >> b);
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value rotateRight(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (int32_t)((a >> b) | (a << (32 - b)));
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value rotateLeft(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
        }else if(argsLength == 1) {
                return args[0];
        }else{
                int32_t a, b;
                napi_get_value_int32(env, args[0], &a);
                napi_get_value_int32(env, args[1], &b);
                int32_t d = (int32_t)((a << b) | ((uint32_t)a >> (32 - b)));
                napi_create_int32(env, d, &result);
        }

        return result;
}

napi_value operate(napi_env env, napi_callback_info info){
        size_t argsLength = 2;
        napi_value args[2];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        napi_value result;
        if(argsLength == 0) {
                napi_create_int32(env, 0, &result);
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
                        char* a = (char*)malloc(sizeof(char) * (aLength + 1));
                        napi_get_value_string_utf8(env, operation, a, aLength + 1, 0);
                        if(aLength < 2) {
                                free(a);
                                return createFalse(env);
                        }
                        char operator = a[0];
                        int32_t value;
                        switch(operator) {
                        case '+':
                                value = (int32_t)atof(a + 1);
                                number += value;
                                break;
                        case '-':
                                value = (int32_t)atof(a + 1);
                                number -= value;
                                break;
                        case '*':
                                value = (int32_t)atof(a + 1);
                                number *= value;
                                break;
                        case '/':
                                value = (int32_t)atof(a + 1);
                                number /= value;
                                break;
                        case ')':
                                value = (int32_t)atof(a + 1);
                                number = (int32_t)((number >> value) | (number << (32 - value)));
                                break;
                        case '(':
                                value = (int32_t)atof(a + 1);
                                number = (int32_t)((number << value) | ((uint32_t)number >> (32 - value)));
                                break;
                        case '>':
                                if(aLength > 2 && a[1] == '>') {
                                        if(aLength > 3 && a[2] == '>') {
                                                value = (int32_t)atof(a + 3);
                                                number = (int32_t)((uint32_t)number >> value);
                                        }else{
                                                value = (int32_t)atof(a + 2);
                                                number >>= value;
                                        }
                                }else{
                                        value = (int32_t)atof(a + 1);
                                        number >>= value;
                                }
                                break;
                        case '<':
                                if(aLength > 2 && a[1] == '<') {
                                        value = (int32_t)atof(a + 2);
                                        number <<= value;
                                }else{
                                        value = (int32_t)atof(a + 1);
                                        number <<= value;
                                }
                                break;
                        default:
                                free(a);
                                return createFalse(env);
                        }
                        free(a);
                }
                napi_create_int32(env, number, &result);
        }

        return result;
}

// TODO -----Object-----

napi_value AddMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a + b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value SubtractMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a - b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value MultiplyMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a * b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value DivideMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a / b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value ShiftLeftMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a << b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value ShiftRightMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (a >> b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value ShiftRightUnsignedMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (int32_t)((uint32_t)a >> b);

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value RotateRightMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (int32_t)((a >> b) | (a << (32 - b)));

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value RotateLeftMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a, b;
        napi_get_value_int32(env, value, &a);
        napi_get_value_int32(env, args[0], &b);

        int32_t newValue = (int32_t)((a << b) | ((uint32_t)a >> (32 - b)));

        napi_value result;
        napi_create_int32(env, newValue, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value SetMethod(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_value me;
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);
        if(argsLength == 0) {
                return me;
        }

        napi_value value;
        napi_get_element(env, me, 0, &value);

        int32_t a;
        napi_get_value_int32(env, args[0], &a);

        napi_value result;
        napi_create_int32(env, a, &result);
        napi_set_element(env, me, 0, result);

        return me;
}

napi_value GetValue(napi_env env, napi_callback_info info){
        napi_value me;
        napi_get_cb_info(env, info, 0, 0, &me, 0);
        napi_value value;
        napi_get_element(env, me, 0, &value);
        return value;
}

napi_value constructor(napi_env env, napi_callback_info info){
        napi_value me;

        size_t argsLength = 1;
        napi_value args[1];
        napi_get_cb_info(env, info, &argsLength, args, &me, 0);

        int32_t initialValue;
        if(argsLength == 0) {
                initialValue = 0;
        }else{
                napi_get_value_int32(env, args[0], &initialValue);
        }

        napi_value value;
        napi_create_int32(env, initialValue, &value);
        napi_set_element(env, me, 0, value);
        return me;
}

napi_value Init (napi_env env, napi_value exports) {
        napi_property_descriptor allDesc[] = {
                {"from", 0, from, 0, 0, 0, napi_default, 0},
                {"add", 0, add, 0, 0, 0, napi_default, 0},
                {"subtract", 0, subtract, 0, 0, 0, napi_default, 0},
                {"multiply", 0, multiply, 0, 0, 0, napi_default, 0},
                {"divide", 0, divide, 0, 0, 0, napi_default, 0},
                {"shiftLeft", 0, shiftLeft, 0, 0, 0, napi_default, 0},
                {"shiftRight", 0, shiftRight, 0, 0, 0, napi_default, 0},
                {"shiftRightUnsigned", 0, shiftRightUnsigned, 0, 0, 0, napi_default, 0},
                {"rotateRight", 0, rotateRight, 0, 0, 0, napi_default, 0},
                {"rotateLeft", 0, rotateLeft, 0, 0, 0, napi_default, 0},
                {"operate", 0, operate, 0, 0, 0, napi_default, 0}
        };
        napi_define_properties(env, exports, 11, allDesc);

        napi_property_descriptor int32AllDesc[] = {
                {"from", 0, from, 0, 0, 0, napi_static, 0},
                {"set", 0, SetMethod, 0, 0, 0, napi_default, 0},
                {"add", 0, AddMethod, 0, 0, 0, napi_default, 0},
                {"subtract", 0, SubtractMethod, 0, 0, 0, napi_default, 0},
                {"multiply", 0, MultiplyMethod, 0, 0, 0, napi_default, 0},
                {"divide", 0, DivideMethod, 0, 0, 0, napi_default, 0},
                {"shiftLeft", 0, ShiftLeftMethod, 0, 0, 0, napi_default, 0},
                {"shiftRight", 0, ShiftRightMethod, 0, 0, 0, napi_default, 0},
                {"shiftRightUnsigned", 0, ShiftRightUnsignedMethod, 0, 0, 0, napi_default, 0},
                {"rotateRight", 0, RotateRightMethod, 0, 0, 0, napi_default, 0},
                {"rotateLeft", 0, RotateLeftMethod, 0, 0, 0, napi_default, 0},
                {"inspect", 0, GetValue, 0, 0, 0, napi_default, 0},
                {"getValue", 0, GetValue, 0, 0, 0, napi_default, 0},
        };
        napi_value cons;
        napi_define_class(env, "Int32", -1, constructor, 0, 13, int32AllDesc, &cons);
        napi_set_named_property(env, exports, "Int32", cons);
        napi_create_reference(env, cons, 1, &Int32Ref);
        return exports;
}

NAPI_MODULE(int32, Init);
