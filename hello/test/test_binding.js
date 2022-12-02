const Hello = require("../dist/binding.js");
const assert = require("assert");

assert(Hello, "The expected function is undefined");

function testBasic()
{
    const result =  Hello("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");