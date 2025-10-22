const net = require('net');

const createTcpServer = (port) => {
  const server = net.createServer((socket) => {
    let sum = 0;
    const logs = [];
  
    socket.on("data", (data) => {
      const num = parseInt(Buffer.from(data));
      sum += num || 0;
      logs.push(`${logs.length + 1}. num = ${num} | sum = ${sum}`);
    });
  
    setInterval(() => socket.write(sum.toString()), 5000);
    setInterval(() => console.log(logs.join("\n")), 5000);
  });

  server.listen(port, () => {
    console.log(`Server started on port ${port}`);
  });
}

createTcpServer(40000);
createTcpServer(50000);