const rpcWSS = require('rpc-websockets').Server;

let server = new rpcWSS({port:4000, host: 'localhost'});

server.register('A', (param)=>{console.log('A',param)}).public();
server.register('B', (param)=>{console.log('B',param)}).public();
server.register('C', (param)=>{console.log('C',param)}).public();