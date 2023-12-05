const rpcWSC = WebSocket = require('rpc-websockets').Client;

let ws = new rpcWSC('ws://localhost:4000');

ws.on('open',()=>{
    ws.subscribe('A');
    ws.on('A',(p)=>{console.log('Event A occurred',p);});
})
