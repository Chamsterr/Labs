const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({port:4000});

wss.on('connection', ws=>{

    const duplex = WebSocket.createWebSocketStream(ws, {encoding:'utf8'});
    let rfile = fs.createReadStream('./text.txt');
    rfile.pipe(duplex);
    
})