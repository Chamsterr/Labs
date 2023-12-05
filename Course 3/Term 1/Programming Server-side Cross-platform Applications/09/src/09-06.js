const rpcWSS = require('rpc-websockets').Server;
const readline = require('readline');

let server = new rpcWSS({ port: 4000, host: 'localhost' });

server.event('A');
server.event('B');
server.event('C');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (input) => {
  switch (input.toUpperCase()) {
    case 'A':
      server.emit('A', { event: 'A' });
      break;
    case 'B':
      server.emit('B', { event: 'B' });
      break;
    case 'C':
      server.emit('C', { event: 'C' });
      break;
    default:
      console.log(`Unknown event: ${input}`);
  }
});
