const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({ port: 4000 });

let k = 0;

wss.on('connection', ws => {

    const duplex = WebSocket.createWebSocketStream(ws, { encoding: 'utf8' });

    const wfile = fs.createWriteStream(`./upload/text${++k}.txt`);
    
    duplex.pipe(wfile);
});

