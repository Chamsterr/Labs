const WebSocket = require('ws');

const ws = new WebSocket('ws://localhost:4000');

const duplex = WebSocket.createWebSocketStream(ws, {encoding:'utf-8'});

duplex.pipe(process.stdout);

process.stdin.pipe(duplex);