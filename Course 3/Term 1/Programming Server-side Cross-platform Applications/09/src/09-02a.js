const fs = require('fs');
const WebSocket = require('ws');

const ws = new WebSocket('ws://localhost:4000');

ws.on('open', () => {
    const rfile = fs.createReadStream('./download/text.txt');
    const duplex = WebSocket.createWebSocketStream(ws, { encoding: 'utf8' });
    rfile.pipe(duplex);
});
