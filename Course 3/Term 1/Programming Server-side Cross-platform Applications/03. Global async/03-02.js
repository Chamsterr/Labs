const http = require('http');
const url = require('url');

const hostname = '127.0.0.1';
const port = 5000;

function factorial(n) {
    if (n == 0) {
        return 1
    }
    else {
        return n * factorial(n - 1)
    }
}

const server = http.createServer((req, res) => {
    if (req.method === 'GET') {
        const parsedUrl = url.parse(req.url, true);
        const queryParams = parsedUrl.query;
        json_resp = {'k': Number(queryParams.k)}


        if (queryParams.k) {
            json_resp.fact = factorial(Number(queryParams.k));
        }


        res.statusCode = 200;
        res.setHeader('Content-Type', 'application/json');
        res.end(JSON.stringify(json_resp));
    } else {
        res.statusCode = 405;
        res.end();
    }
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});
