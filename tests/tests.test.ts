import { add, rotateLeft, rotateRight } from "../src/lib";

describe("Add", function () {
    it("should add step-by-step and would overflow", function () {
        let n = 0;

        for (let i = 0;i < 10000;++i) {
            n = add(n, 98766455);
        }

        expect(n).toBe(-177928080);
    });
});

describe("Rotate", function () {
    it("should rotate right", function () {
        let n = 0b00000000000000000000000100000001;
        n = rotateRight(n, 8);
        expect(n).toBe(0b00000001000000000000000000000001);
    });

    it("should rotate left", function () {
        let n = 0b10000000000000000000000100000000;
        n = rotateLeft(n, 1);
        expect(n).toBe(0b00000000000000000000001000000001);
    });
});
