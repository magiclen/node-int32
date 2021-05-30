Int32
=================================

[![CI](https://github.com/magiclen/node-int32/actions/workflows/ci.yml/badge.svg)](https://github.com/magiclen/node-int32/actions/workflows/ci.yml)

## Usage

#### add

```javascript
const n = int32.add(1, 2); // 3
```

#### subtract

```javascript
const n = int32.subtract(1, 2); // -1
```

#### multiply

```javascript
const n = int32.subtract(2, 6); // 12
```

#### divide

```javascript
const n = int32.divide(6, 4); // 1
```

#### pow

```javascript
const n = int32.pow(2, 3); // 8
```

#### shiftLeft

```javascript
const n = int32.shiftLeft(5, 2); // 20
```

#### shiftRight

```javascript
const n1 = int32.shiftRight(5, 2); // 1
const n2 = int32.shiftRight(6, 1); // 3
const n3 = int32.shiftRight(-5, 1); // -3
```

#### shiftRightUnsigned

```javascript
const n = int32.shiftRightUnsigned(-5, 1); // 2147483645
```

#### rotateLeft

```javascript
const n = int32.rotateLeft(0b10000000000000000000000100000000, 1); // 0b00000000000000000000001000000001
```

#### rotateRight

```javascript
const n = int32.rotateRight(0b00000000000000000000000100000001, 8); // 0b00000001000000000000000000000001
```

## License

[MIT](LICENSE)
