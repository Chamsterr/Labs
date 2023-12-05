const dgram = require('dgram');

const server = dgram.createSocket('udp4');

server.on('message', (msg, rinfo) => {
  server.send(`ECHO: ${msg}`, rinfo.port, rinfo.address);
});

server.bind(3000, () => {
  console.log('Server started on port 3000');
});