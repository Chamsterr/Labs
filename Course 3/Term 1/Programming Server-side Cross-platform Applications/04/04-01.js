const http = require('http');
const fs = require('fs');
const url = require('url');
const database = require('./DB.js')

let db = new database.DB();

const handleRequestData = (req, res, action) => {
    req.on('data', (data) => {
        let r = JSON.parse(data);

        if (r.id === '' || r.name === '' || r.bday === '') {
            res.writeHead(400, { 'Content-Type': 'application/json; charset=utf-8' });
            res.end(JSON.stringify({ error: 'Поля не могут быть пустыми' }));
            return;
        }
        if (action != "delete" && !checkDate(r.bday)) {
            console.log(r.bday)
            res.writeHead(400, { 'Content-Type': 'application/json; charset=utf-8' });
            res.end(JSON.stringify({ error: 'Дата рождения не может быть больше текущей' }));
            return;
        }

        db.db_actions[action](r).then(data => {
            res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });
            res.end(JSON.stringify(data));
        }).catch(err => {
            console.log(err)
            res.writeHead(400, { 'Content-Type': 'application/json; charset=utf-8' });
            res.end(JSON.stringify(err));
        });
    });
};

db.on('GET', (req, res) => {
    console.log('DB GET');
    db.select().then((results) => {
        res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });
        res.end(JSON.stringify(results));
    });
});

db.on('POST', (req, res) => {
    console.log('DB POST');
    handleRequestData(req, res, 'insert');
});

db.on('PUT', (req, res) => {
    console.log('DB PUT');
    handleRequestData(req, res, 'update');
});

db.on('DELETE', (req, res) => {
    console.log('DB DELETE');
    handleRequestData(req, res, 'delete');
});

let checkDate = (date) => {
    console.log(date)
    let pattern = /(\d{2})\-(\d{2})\-(\d{4})/;
    let new_date = date.replace(pattern, '$3-$2-$1');
    return new Date(new_date) <= new Date();
}

http.createServer((req, res) => {
    if (url.parse(req.url).pathname === '/') {
        let html = fs.readFileSync("./04-01.html", 'utf8');
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf8' });
        res.end(html);
    } else if (url.parse(req.url).pathname === "/api/db") {
        db.emit(req.method, req, res);
    }
}).listen(5000, () => console.log('Server is running at http://localhost:5000'));