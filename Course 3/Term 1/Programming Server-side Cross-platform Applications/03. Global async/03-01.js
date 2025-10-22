const http = require('http');
const readline = require('readline');

const hostname = '127.0.0.1';
const port = 5000;
let currentState = 'norm';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


function updateState(newState) {
  if (['norm', 'stop', 'test', 'idle', 'exit'].includes(newState)) {
    currentState = newState;
    console.log(`Состояние приложения: ${currentState}`);
  } else {
    console.log(`Недопустимое состояние: ${newState}`);
  }
}

const server = http.createServer((req, res) => {
  res.writeHead(200, {"content-type": "text/html; charset=utf-8"})
  res.end(`
    <html>
    <head>
      <title>Состояние приложения</title>
    </head>
    <body>
      <h1>Состояние приложения: ${currentState}</h1>
    </body>
    </html>
  `);
});


server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});

rl.setPrompt('Введите новое состояние: ');
rl.prompt();
rl.on('line', (input) => {
  const newState = input.trim();
  if (newState === 'exit') {
    rl.close();
    server.close();
    process.exit(0);
  } else {
    updateState(newState);
    rl.prompt();
  }
});
