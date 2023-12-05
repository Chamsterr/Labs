const dgram = require('dgram');

const client = dgram.createSocket("udp4");

client.on("message", (msg) => {
    console.log(msg.toString());
    client.close();
});

client.on("close", () => {
    console.log("Disconnected from server");
});

client.send("Hello from client", 3000, '127.0.0.1');