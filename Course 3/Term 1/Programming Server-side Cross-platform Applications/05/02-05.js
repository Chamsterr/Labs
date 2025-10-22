const http = require('http');
const fs = require('fs');
const url = require('url');
const send = require('./m05_KNV');

let server = http.createServer((req, resp) => {
    resp.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });

    if (url.parse(req.url).pathname == '/' && req.method == 'GET') {
        resp.end(fs.readFileSync('02-05.html'));
    }
    else if (url.parse(req.url).pathname == '/' && req.method == 'POST') {
        console.log('POST');
        req.on('data', chunk => {
            let param = JSON.parse(chunk);
            console.log(`${param.reciver}, ${param.sender}, ${param.message}`)
            send(param.sender, param.password, param.reciver, param.message);
        });
        req.on('end', () => {
            resp.end(`OK`);
        });
    }
    else
        resp.end('Not Found');
})

server.listen(5000);
console.log('Server Started');