Int32
=================================

[![CI](https://github.com/magiclen/node-int32/actions/workflows/ci.yml/badge.svg)](https://github.com/magiclen/node-int32/actions/workflows/ci.yml)

Use Rust to compute 32-bit signed integers and wrap around at the boundary.

You need to set up the Rust development environment: [rustup](https://rustup.rs/)

## Usage

#### add

```typescript
import { add } from "int32";

const n = add(1, 2); // 3
```

#### subtract

```typescript
import { subtract } from "int32";

const n = subtract(1, 2); // -1
```

#### multiply

```typescript
import { multiply } from "int32";

const n = multiply(2, 6); // 12
```

#### divide

```typescript
import { divide } from "int32";

const n = divide(6, 4); // 1
```

#### pow

```typescript
import { pow } from "int32";

const n = pow(2, 3); // 8
```

#### shiftLeft

```typescript
import { shiftLeft } from "int32";

const n = shiftLeft(5, 2); // 20
```

#### shiftRight

```typescript
import { shiftRight } from "int32";

const n1 = shiftRight(5, 2); // 1
const n2 = shiftRight(6, 1); // 3
const n3 = shiftRight(-5, 1); // -3
```

#### shiftRightUnsigned

```typescript
import { shiftRightUnsigned } from "int32";

const n = shiftRightUnsigned(-5, 1); // 2147483645
```

#### rotateLeft

```typescript
import { rotateLeft } from "int32";

const n = rotateLeft(0b10000000000000000000000100000000, 1); // 0b00000000000000000000001000000001
```

#### rotateRight

```typescript
import { rotateRight } from "int32";

const n = rotateRight(0b00000000000000000000000100000001, 8); // 0b00000001000000000000000000000001
```

## License

[MIT](LICENSE)
