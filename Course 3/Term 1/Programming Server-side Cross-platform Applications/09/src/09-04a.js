const WebSocket = require('ws');

const clientName = process.argv[2];

const ws = new WebSocket('ws://localhost:4000');

ws.on('open', () => {
  console.log('Connected to the server');
  ws.on('message', data => {
    console.log('Received:', JSON.parse(data));
  });
  let k = 0;
  ws.send(JSON.stringify({ client: clientName, timestamp: Date.now() }));
});