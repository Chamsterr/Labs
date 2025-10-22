const express = require('express');
const cors = require('cors');
const app = express();

app.use(express.json());
app.use(cors());

app.post('/generate', (req, res) => {
    const n = parseInt(req.headers['x-rand-n']);    
    const count = Math.floor(Math.random() * 6) + 5;
    const numbers = Array.from({ length: count }, () => Math.floor(Math.random() * (2 * n + 1)) - n);
    res.json(numbers);
});

app.listen(3000, () => console.log('Server started on port 3000'));
