import express from 'express';
import {Routes} from "./routes/index.js";
import {dbMiddleware} from "./middlewares/index.js";
import bodyParser from 'body-parser';

const app = new express();
const PORT = 3000;

app.use(express.static('public'));
app.use(dbMiddleware);
app.use(bodyParser.json());
app.use(bodyParser.urlencoded());

app.use(Routes);

app.listen(PORT, () => {
  console.log(`Server started on PORT ${PORT}`);
});
