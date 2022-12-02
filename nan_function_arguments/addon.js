const addon = require('bindings')('addon.node')

console.log('2+3:', addon.add(2, 3));