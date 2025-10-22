const url = require('url');
const fs = require('fs');
const { parse } = require('querystring');
const parseString = require('xml2js').parseString;
const xmlBuilder = require('xmlbuilder');
const multiParty = require('multiparty');

class Service {
    constructor(server, sockets) {
        this.server = server;
        this.sockets = sockets;
    }

    Connection = (req, res) => {
        let setParameter = url.parse(req.url, true).query.set;
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });

        if (!setParameter) {
            res.end(`<h1>KeepAliveTimeout: ${this.server.keepAliveTimeout}</h1>`);
        } else if (Number(setParameter)) {
            console.log('KeepAliveTimeout: ' + setParameter);
            this.server.keepAliveTimeout = Number(setParameter);
            res.end(`<h1>New KeepAliveTimeout = ${this.server.keepAliveTimeout}</h1>`);
        } else {
            res.end(`<h1>Enter correct keepAliveTimeout. </br>Your value: ${setParameter}</h1>`);
        }
    };

    Headers = (req, res) => {
        let i = 0;
        let result = '<h1>Заголовки запроса:</h1>';
        for (let key in req.headers) {
            result += `${++i}. ${key}: ${req.headers[key]}<br/>`;
        }

        i = 0;
        result += '<br/><h1>Заголовки ответа:</h1>';
        res.setHeader('Connection', 'keep-alive');
        res.setHeader('Content-Type', 'text/html; charset=utf-8');
        let resHeaders = res.getHeaders();
        console.log('response headers: ', resHeaders);
        for (let key in resHeaders) {
            result += `${++i}. ${key}: ${resHeaders[key]}<br/>`;
        }

        res.writeHead(200);
        res.end(result);
    }

    Parameters = (req, res) => {
        const url = require('url');
        const urlParts = url.parse(req.url, true);
        let x, y, source;

        if (urlParts.query.x !== undefined && urlParts.query.y !== undefined) {
            x = urlParts.query.x;
            y = urlParts.query.y;
            source = 'query';
        } else {
            let params = urlParts.pathname.split('/');
            if (params.length >= 3) {
                x = params[2];
                y = params[3];
                source = 'route';
            }
        }

        console.log([x, y], source);
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });

        if (x && y && !isNaN(x) && !isNaN(y)) {
            console.log(`x = ${x}; y = ${y} from ${source}`);
            res.end(`<h1>
                        x = ${x}; y = ${y} <br/>
                        x + y = ${+x + +y} <br/>
                        x - y = ${x - y} <br/>
                        x * y = ${x * y} <br/>
                        x / y = ${x / y}
                    </h1>`);
        } else if (source === 'route') {
            res.end(`<h1>${req.url}</h1>`);
        } else {
            res.end(`<h1>Введите корректные параметры x и y в запросе или маршруте. </h1>`);
        }
    }

    Sockets = (req, res) => {
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
        res.end(`<h1>
                    Client port: ${res.socket.remotePort} <br/>
                    Client ip: ${res.socket.remoteAddress} <br/>
                    Server port: ${res.socket.localPort} <br/>
                    Server ip: ${res.socket.localAddress} <br/>
                    </h1>`);
    }

    ResponseStatus = (req, res) => {
        let code = url.parse(req.url, true).query.code;
        let message = url.parse(req.url, true).query.mess;

        console.log('code = ' + code);
        console.log('mess = ' + message);

        if (code === undefined || message === undefined) {
            res.writeHead(405, 'Incorrect parameters', { 'Content-Type': 'text/html; charset=utf-8' });
            res.end('<h1>Enter parameters in URI: code = int, mess = string.</h1>');
        } else if (Number(code)) {
            if (+code >= 200 && +code < 600) {
                res.writeHead(+code, message, { 'Content-Type': 'text/html; charset=utf-8' });
                res.end(`<h1>Responsed with Code = ${code} and Message = ${message}</h1>`);
            } else {
                res.writeHead(406, 'Invalid StatusCode', { 'Content-Type': 'text/html; charset=utf-8' });
                res.end('<h1>Enter valid StatusCode (200-599).</h1>')
            }
        } else {
            res.writeHead(407, 'Incorrect StatusCode', { 'Content-Type': 'text/html; charset=utf-8' });
            res.end('<h1>Enter correct StatusCode (200-599).</h1>')
        }
    }

    FormParameter = (req, res) => {
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });

        if (req.method === 'GET') {
            res.end(fs.readFileSync('./form.html'));
        } else if (req.method === 'POST') {
            let body = '';
            let parm = '';
            req.on('data', chunk => {
                body += chunk.toString();
            });

            req.on('end', () => {
                parm = parse(body);
                console.log('parm = ', parm);
                res.end(`<h2>
                            Text: ${parm.inpText} <br/>
                            Number: ${parm.inpNumber} <br/>
                            Date: ${parm.inpDate} <br/>
                            Checked checkbox(s): ${parm.inpCheck} <br/>
                            Selected radiobutton: ${parm.inpRadio} <br/>
                            Textarea: ${parm.inpTextArea} <br/>
                            Submit: ${parm.inpSubmitForm} <br/>
                        </h2>`);
            });
        } else {
            res.writeHead(408, 'Incorrect method', { 'Content-Type': 'text/html; charset=utf-8' });
            res.end('<h1>Incorrect method</h1>');
        }
    }

    JSON = (req, res) => {
        res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });
        let data = '';

        req.on('data', chunk => {
            data += chunk.toString();
        });
        req.on('end', () => {
            data = JSON.parse(data);
            let result = {};
            result._comment = "Ответ. Лабораторная работа 6";
            result.x_plus_y = data.x + data.y;
            result.concatination_s_and_o = `${data.s}: ${data.o.surname}, ${data.o.name}`;
            result.length_m = data.m.length;
            res.end(JSON.stringify(result, null, 2));
        });
    }

    XML = (req, res) => {
        let xmlString = '';

        req.on('data', data => {
            xmlString += data.toString();
        });
        req.on('end', () => {
            parseString(xmlString, (err, result) => {
                if (err) {
                    res.end(`<result>parseString returned error: ${err}</result>`);
                    return;
                }
                let sum = 0;
                let mess = '';
                result.request.x.forEach(el => {
                    sum += Number.parseInt(el.$.value);
                })
                result.request.m.forEach(el => {
                    mess += el.$.value;
                })

                let xmlDoc = xmlBuilder.create('response')
                    .att('id', +result.request.$.id + 10)
                    .att('request', result.request.$.id);
                xmlDoc.ele('sum', { element: 'x', sum: `${sum}` });
                xmlDoc.ele('concat', { element: 'm', result: `${mess}` });
                let rc = xmlDoc.toString({ pretty: true });
                console.log(rc);

                res.writeHead(200, { 'Content-Type': 'text/xml; charset=utf-8' });
                res.end(rc);
            });
        })
    }

    Files = (req, res) => {
        let filename = url.parse(req.url).pathname.split('/')[2];

        if (filename === undefined) {
            fs.readdir('./static', (err, files) => {
                if (err) {
                    res.end('<h1>Unable to find ./static directory<h1>');
                    return;
                }
                res.setHeader('X-static-files-count', `${files.length}`);
                res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
                res.end(`<h1>Count of files in ./static directory: ${files.length}.</h1>`);
            });
        } else {
            try {
                res.setHeader('Content-Type', 'application/octet-stream');
                res.end(fs.readFileSync(`static/${filename}`));
            } catch (err) {
                res.writeHead(404, 'Resource not found', { 'Content-Type': 'text/html; charset=utf-8' });
                res.end('<h1>Error 404: Resource not found.</h1>')
            }
        }
    }

    Upload = (req, res) => {
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });

        if (req.method === 'GET') {
            res.end(fs.readFileSync('./upload.html'))
        }

        else if (req.method === 'POST') {
            let form = new multiParty.Form({ uploadDir: './static' });
            form.on('file', (name, file) => {
                console.log(`name = ${name}; original filename: ${file.originalFilename}; path = ${file.path}`);
            });
            form.on('error', err => { res.end(`<h1>form returned error: ${err}</h1>`) });
            form.on('close', () => {
                res.end('<h1>File successfully uploaded.</h1>');
            });
            form.parse(req);
        }

        else {
            res.writeHead(408, 'Incorrect method', { 'Content-Type': 'text/html; charset=utf-8' });
            res.end('<h1>408: Incorrect method</h1>');
        }
    }
}

exports.Service = Service;