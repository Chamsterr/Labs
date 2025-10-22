const WebSocket = require('ws');
const ws = new WebSocket('ws://localhost:4000');

ws.on('open', function open() {
  ws.send('08-03a-client: Hello, server!');
});

ws.on('message', function incoming(data) {
  console.log(data.toString());
});