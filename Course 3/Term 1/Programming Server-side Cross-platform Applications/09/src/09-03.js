const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 4000 });

let messageNumber = 0;
let connections = 0;

wss.on('connection', ws => {
  connections++;
  console.log('New connection. Total connections:', connections);

  ws.on('pong', (data) => {
    console.log('on pong: ', data.toString());
  });

  ws.on('close', () => {
    connections--;
    console.log('Connection closed. Total connections:', connections);
  });
});

setInterval(() => {
  wss.clients.forEach(client => {
    if (client.readyState === WebSocket.OPEN) {
      client.send(`09-03-server: ${++messageNumber} || `);
    }
  });
}, 15000);

setInterval(() => {
  wss.clients.forEach(client => {
    if (client.readyState === WebSocket.OPEN) {
      console.log('server: ping');
      client.ping('server: ping');
    }
  });
  console.log('Total active connections:', connections);
}, 5000);
