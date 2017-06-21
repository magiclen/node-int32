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
