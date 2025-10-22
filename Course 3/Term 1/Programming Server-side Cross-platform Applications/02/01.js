const http = require('http');
const fs = require('fs');

const hostname = '127.0.0.1';
const port = 5000;


const server = http.createServer((req, res) => {
    let html = fs.readFileSync('./01.html')
    res.writeHead(200, {"content-type": "text/html; charset=utf-8"})
    res.end(html);
});
   
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});