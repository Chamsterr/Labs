const http = require('http');
const url = require('url');
const fs = require('fs');

const hostname = '127.0.0.1';
const port = 5000;

function factorial(n) {
    if (n === 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

const server = http.createServer((req, res) => {
    if (req.method === 'GET') {
        const parsedUrl = url.parse(req.url, true)
        const path = url.parse(req.url, true).pathname
        if (path === "/factorial") {
            const queryParams = parsedUrl.query;

            if (queryParams.k) {
                const k = Number(queryParams.k);
                const fact = factorial(k);

                const json_resp = {
                    'k': k,
                    'fact': fact
                };

                res.statusCode = 200;
                res.setHeader('Content-Type', 'application/json');
                res.end(JSON.stringify(json_resp));
            } else {
                res.statusCode = 400;
                res.setHeader('Content-Type', 'application/json');
                res.end('{"error": "Parameter k is missing or invalid"}');
            }
        } else {
            try {
                let html = fs.readFileSync('./03-03.html', 'utf8');
                res.setHeader('Content-Type', 'text/html');
                res.end(html);
            } catch (err) {
                res.statusCode = 500;
                res.setHeader('Content-Type', 'text/plain');
                res.end('Error reading HTML file');
            }
        }
    } else {
        res.statusCode = 405;
        res.end();
    }
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});


// const http = require('http');
// const url = require('url');
// const fs = require('fs');
// const hostname = '127.0.0.1';
// const port = 5000;

// function factorial(n) {
//     if (n === 0) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }

// const server = http.createServer((req, res) => {
//     let rc = JSON.stringify({k: 0});
//     let path = url.parse(req.url).pathname;
//     if (path === "/factorial"){
//         let param = url.parse(req.url, true).query.k;
//         if (typeof param != "undefined"){
//             let k = parseInt(param);
//             if (Number.isInteger(k)){
//                 res.writeHead(200, { "Content-Type": "application/json; charset=utf-8"});
//                 res.end(JSON.stringify({k: k, factorial: factorial(k)}))
//             }
//         }
//     }
//     else if (path === "/"){
//         let html = fs.readFileSync('03-03.html');
//         res.writeHead(200, {"Content-Type": "text/html; charset=utf-8"})
//         res.end(html)
//     }
//     else{
//         res.end(rc)
//     }
// })

// server.listen(port, hostname, () => {
//     console.log(`Server running at http://${hostname}:${port}/`);
// });