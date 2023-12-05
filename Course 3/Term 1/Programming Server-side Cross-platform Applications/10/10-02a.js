const net = require('net');

if (process.argv.length < 4) {
  console.log("Usage: node script.js <port> <message>");
  process.exit(1);
}

const port = process.argv[2];
const message = process.argv[3];

const client = new net.Socket();

client.on("data", (data) => {
  console.log('Received: ' + data.toString());
});

client.on("end", () => {
  console.log("Disconnected from server");
});

client.on("error", (err) => {
  console.error("Connection error: " + err.message);
});

client.connect(port, "127.0.0.1", () => {
  console.log("Connected to server");
  sendMessage();
});

function sendMessage() {
  client.write(message);
  setTimeout(sendMessage, 1000);
}