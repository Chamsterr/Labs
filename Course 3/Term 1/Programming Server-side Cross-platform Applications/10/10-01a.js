const net = require('net');

const client = new net.Socket();
client.connect(3000, '127.0.0.1', () => {
    client.write('Hello, server!');
});

client.on('data', (data) => {
    console.log('Received: ' + data);
});
