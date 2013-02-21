var assert = require('assert');
var binding = require('./build/Release/binding');

assert.equal('world', binding.hello());
console.log('binding.hello() =', binding.hello());
console.log('binding.add(40, 2) =', binding.add(40, 2));
