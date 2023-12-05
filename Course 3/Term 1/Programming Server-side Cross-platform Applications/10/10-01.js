const net = require('net');

const server = net.createServer((socket) => {
    socket.on('data', (data) => {
        socket.write(`ECHO: ${data}`);
    });
});

server.listen(8080, () => {
    console.log('Server listening on port 8080');
});