'use strict';

const expect = require('chai').expect;
const int32 = require('../index');

describe('Add', function() {
  it('should add step-by-step and would overflow', function() {
    var n = 0;
    for (let i = 0; i < 10000; ++i) {
      n = int32.add(n, 98766455);
    }
    expect(n).to.equal(-177928080);
  });

  it('should add at one time and would overflow', function() {
    var ops = [];
    for (let i = 0; i < 10000; ++i) {
      ops.push('+98766455');
    }
    var n = int32.operate(0, ops);
    expect(n).to.equal(-177928080);
  });

  it('should add as an object and would overflow', function() {
    var i32 = new int32.Int32();
    for (let i = 0; i < 10000; ++i) {
      i32.add(98766455);
    }
    var n = i32.getValue();
    expect(n).to.equal(-177928080);
  });
});

describe('Rotate', function() {
  it('should rotate right', function() {
    var n = 0b00000000000000000000000100000001;
    n = int32.rotateRight(n, 8);
    expect(n).to.equal(0b00000001000000000000000000000001);
  });
  it('should rotate left', function() {
    var n = 0b10000000000000000000000100000000;
    n = int32.rotateLeft(n, 1);
    expect(n).to.equal(0b00000000000000000000001000000001);
  });
});
