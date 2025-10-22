const net = require('net');

const server = net.createServer((socket) => {
    socket.on('data', (data) => {
        socket.write(`ECHO: ${data}`);
    });
});

server.listen(3000, () => {
    console.log('Server listening on port 3000');
});