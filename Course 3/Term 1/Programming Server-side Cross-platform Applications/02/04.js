const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
    res.setHeader('Access-Control-Allow-Origin', '*');

    res.setHeader("Content-Type", "text/plain; charset=utf-8");
    if (req.method === 'GET') {
        if (req.url === "/api/name") {
            res.statusCode = 200;
            res.end(`Ковкель Никита Викторович`);
        } else {
            res.statusCode = 404;
            res.end("Страница не найдена");
        }
    } else {
        res.statusCode = 405;
        res.end("Метод не разрешен");
    }
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});
