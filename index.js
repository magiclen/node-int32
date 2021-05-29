const addon = require("./native/index.node");

const {
    add, subtract, multiply, divide, pow, shiftLeft, shiftRight, shiftRightUnsigned, rotateLeft, rotateRight,
} = addon;

exports.add = add;
exports.subtract = subtract;
exports.multiply = multiply;
exports.divide = divide;
exports.pow = pow;
exports.shiftLeft = shiftLeft;
exports.shiftRight = shiftRight;
exports.shiftRightUnsigned = shiftRightUnsigned;
exports.rotateLeft = rotateLeft;
exports.rotateRight = rotateRight;
