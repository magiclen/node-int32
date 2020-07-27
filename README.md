Int32
=================================

## Introduction

This module uses Rust to compute 32-bit signed integers and wrap around at the boundary.

In JavaScript, the size of type `number` is 64 bits. A `number` can be used to represent an IEEE-754 double-precision number or a 53-bit integer. If you need to compute something and integers in your computation are overflowing/underflowing, this kind of algorithms is hard to be implemented by using the type `number` in Node.js.

## Installation

Setting up your Rust development environment: [rustup](https://rustup.rs/)

Run `npm i` or `npm install` to install.

```bash
npm install int32
```

If you want to save this module to package.json, add the `--save` option.

```bash
npm install int32 --save
```

## Initialization

```javascript
const int32 = require('int32');
```

```javascript
import int32 from 'int32';
```

## Usage

#### add

```javascript
let n = int32.add(1, 2); // 3
```

#### subtract

```javascript
let n = int32.subtract(1, 2); // -1
```

#### multiply

```javascript
let n = int32.subtract(2, 6); // 12
```

#### divide

```javascript
let n = int32.divide(6, 4); // 1
```

#### pow

```javascript
let n = int32.pow(2, 3); // 8
```

#### shiftLeft

```javascript
let n = int32.shiftLeft(5, 2); // 20
```

#### shiftRight

```javascript
let n1 = int32.shiftRight(5, 2); // 1
let n2 = int32.shiftRight(6, 1); // 3
let n3 = int32.shiftRight(-5, 1); // -3
```

#### shiftRightUnsigned

```javascript
let n = int32.shiftRightUnsigned(-5, 1); // 2147483645
```

#### rotateLeft

```javascript
let n = int32.rotateLeft(0b10000000000000000000000100000000, 1); // 0b00000000000000000000001000000001
```

#### rotateRight

```javascript
let n = int32.rotateRight(0b00000000000000000000000100000001, 8); // 0b00000001000000000000000000000001
```

## License

[MIT](LICENSE)
