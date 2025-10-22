const http = require('http');
const url = require('url');
const serverSockets = new Set();
const {Service} = require('./m0600');

const server = http.createServer();

const httpHandler = ((req, res) => {
    const service = new Service(server, serverSockets);
    if (req.method === 'GET') {
        switch (url.parse(req.url).pathname.split('/')[1]) {
            case '':
                res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
                res.end('<h1>Lab08</h1>');
                break;
            case 'connection':
                service.Connection(req, res);
                break;
            case 'headers':
                service.Headers(req, res);
                break;
            case 'parameter':
                service.Parameters(req, res);
                break;
            case 'socket':
                service.Sockets(req, res);
                break;
            case 'resp-status':
                service.ResponseStatus(req, res);
                break;
            case 'formparameter':
                service.FormParameter(req, res);
                break;
            case 'files':
                service.Files(req, res);
                break;
            case 'upload':
                service.Upload(req, res);
                break;
            default:
                res.writeHead(404, {'Content-Type': 'text/html; charset=utf-8'});
                res.end('<h1>Not found</h1>')
        }
    } else if (req.method === 'POST') {
        switch (url.parse(req.url).pathname.split('/')[1]) {
            case 'formparameter':
                service.FormParameter(req, res);
                break;
            case 'json':
                service.JSON(req, res);
                break;
            case 'xml':
                service.XML(req, res);
                break;
            case 'upload':
                service.Upload(req, res);
                break;
            default:
                res.writeHead(404, {'Content-Type': 'text/html; charset=utf-8'});
                res.end('<h1>Not found</h1>')
        }
    } else {
        res.writeHead(409, 'Incorrect method', {'Content-Type': 'text/html; charset=utf-8'});
        res.end('<h1>Incorrect request method</h1>')
    }

});

server.on('request', httpHandler);
server.on('connection', socket => {
    serverSockets.add(socket);
})
server.listen(5000, () => console.log("Server is running at http://localhost:5000"));