/**
 * Computes <code>a + b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a + b</code>
 */
export declare function add(a: number, b: number): number;

/**
 * Computes <code>a - b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a - b</code>
 */
export declare function subtract(a: number, b: number): number;

/**
 * Computes <code>a * b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a * b</code>
 */
export declare function multiply(a: number, b: number): number;

/**
 * Computes <code>a / b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a / b</code>
 */
export declare function divide(a: number, b: number): number;

/**
 * Computes <code>a ^ b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a ^ b</code>
 */
export declare function pow(a: number, b: number): number;

/**
 * Computes <code>a << b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a << b</code>
 */
export declare function shiftLeft(a: number, b: number): number;

/**
 * Computes <code>a >> b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a >> b</code>
 */
export declare function shiftRight(a: number, b: number): number;

/**
 * Computes <code>a >>> b</code>, wrapping around at the boundary of an 32-bit integer.
 * @param  a
 * @param  b
 * @return The result of <code>a >>> b</code>
 */
export declare function shiftRightUnsigned(a: number, b: number): number;

/**
 * Shifts the bits to the right by a specified amount n, wrapping the truncated bits to the beginning of the resulting 32-bit integer.
 * @param  a
 * @param  n
 * @return The result of <code>(a << n) | (a >>> (32 - n))</code> (approximately)
 */
export declare function rotateLeft(a: number, n: number): number;

/**
 * Shifts the bits to the right by a specified amount n, wrapping the truncated bits to the beginning of the resulting 32-bit integer.
 * @param  a
 * @param  n
 * @return The result of <code>(a >>> n) | (a << (32 - n))</code> (approximately)
 */
export declare function rotateRight(a: number, n: number): number;