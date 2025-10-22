const express = require('express');
const cors = require('cors');
const app = express();

app.use(express.json());
app.use(cors());

app.use(express.json());

app.post('/calculate', (req, res) => {
    setTimeout(() => {
        const x = parseInt(req.headers['x-value-x']);
        const y = parseInt(req.headers['x-value-y']);
        const z = x + y;
        res.set('x-value-z', z);
        res.set('Access-Control-Expose-Headers', 'x-value-z');
        res.send();
    }, 10000);
});


app.post('/generate', (req, res) => {
    setTimeout(() => {
        const n = parseInt(req.headers['x-rand-n']);
        const count = Math.floor(Math.random() * 6) + 5;
        const numbers = Array.from({ length: count }, () => Math.floor(Math.random() * (2 * n + 1)) - n);
        res.json(numbers);
    }, 1000);
});

app.listen(3000, () => console.log('Server started on port 3000'));
