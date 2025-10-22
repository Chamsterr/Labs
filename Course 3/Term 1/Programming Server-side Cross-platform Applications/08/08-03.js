const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 4000 });

wss.on('connection', ws => {
  ws.on('message', message => {
    console.log('Received: %s', message);
    wss.clients.forEach(client => {
      if (client !== ws && client.readyState === WebSocket.OPEN) {
        client.send(`08-03-server: ${message}`);
      }
    });
  });
});