Int32
=================================

## Introduction

This module uses N-API to compute 32 bits integers and preserves the property of overflowing, which allows you can do some 32-bit integer computing (such as hashing) in Node.js.

In JavaScript, the length of type `number` is 64 bits. A `number` can be used to represent an IEEE-754 double-precision number or a 53-bit integer. If you need compute something and integers in your computation are overflowing or underflowing, this kind of algorithms is hard to be implemented by using the type `number` in Node.js.

## Installation

Run `npm i` or `npm install` to install.

```bash
npm install int32
```

If you want to save this module to package.json, please add `--save` option.

```bash
npm install int32 --save
```

## Initialization

Import this module by using `require` function.

```javascript
const int32 = require('int32'); // static functions
const Int32 = int32.Int32; // instance methods
```

## Static Usage

### Add

```javascript
var n = int32.add(1, 2); // 3
```

### Subtract

```javascript
var n = int32.subtract(1, 2); // -1
```

### multiply

```javascript
var n = int32.subtract(2, 6); // 12
```

### divide

```javascript
var n = int32.divide(6, 4); // 1
```

### shiftLeft

```javascript
var n = int32.shiftLeft(5, 2); // 20
```

### shiftRight

```javascript
var n1 = int32.shiftRight(5, 2); // 1
var n2 = int32.shiftRight(6, 1); // 3
var n3 = int32.shiftRight(-5, 1); // -3
```

### shiftRightUnsigned

```javascript
var n = int32.shiftRightUnsigned(-5, 1); // 2147483645
```

### rotateRight

```javascript
var n = int32.rotateRight(0b00000000000000000000000100000001, 8); // 0b00000001000000000000000000000001
```

### rotateLeft

```javascript
var n = int32.rotateLeft(0b10000000000000000000000100000000, 1); // 0b00000000000000000000001000000001
```

### operate

```javascript
var n1 = int32.operate(1, ['+1','*3','-3','/3']); // (((1+1)*3)-3)/3 = 1
var n2 = int32.operate(0xFFFF0000, ['<8', '>24']); // 11111111111111110000000000000000 << 8 = 11111111000000000000000000000000
                                                   // 11111111000000000000000000000000 >> 24 = 11111111111111111111111111111111
                                                   // = -1
var n3 = int32.operate(0xFFFF0000, ['<8', '>>>24']); // 11111111111111110000000000000000 << 8 = 11111111000000000000000000000000
                                                     // 11111111000000000000000000000000 >>> 24 = 00000000000000000000000011111111
                                                     // = 255
```

## Class Usage

### Create an Instance

```javascript
var i32 = new Int32(1);
```

or

```javascript
var i32 = int32.from(1);
```

or

```javascript
var i32 = Int32.from(1);
```

### Methods

```javascript
var n1 = i32.add(1).multiply(3).subtract(3).divide(3).getValue(); // 1
i32.set(0xFFFF0000);
var n2 = i32.shiftLeft(8).shiftRight(24).getValue(); // -1
i32.set(0xFFFF0000);
var n3 = i32.shiftLeft(8).shiftRightUnsigned(24).getValue(); // -255
i32.set(0b00000000000000000000000100000001);
var n4 = i32.rotateRight(8); // 0b00000001000000000000000000000001
```

## Tests

To run the test suite, first install the dependencies, then run `npm test`:

```bash
npm install
npm test
```

## License

[MIT](LICENSE)
