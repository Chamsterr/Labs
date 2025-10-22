const WebSocket = require('ws');
const fs = require('fs');
const stream = require('stream');

const wss = new WebSocket.Server({ port: 4000 });

wss.on('connection', ws => {
    const duplex = WebSocket.createWebSocketStream(ws, { encoding: 'utf8' });
    const wfile = fs.createWriteStream('./text.txt');
    duplex.pipe(wfile);
});
