const express = require('express');
const cors = require('cors');
const app = express();

app.use(express.json());
app.use(cors());
app.post('/calculate', (req, res) => {
    const x = parseInt(req.headers['x-value-x']);
    const y = parseInt(req.headers['x-value-y']);
    const z = x + y;
    res.set('x-value-z', z);
    res.set('Access-Control-Expose-Headers', 'x-value-z');
    res.send();
});

app.listen(3000, () => console.log('Server started on port 3000'));
