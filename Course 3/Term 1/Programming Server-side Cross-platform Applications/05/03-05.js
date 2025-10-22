require("dotenv").config();

const send = require('./m05_KNV')

send(process.env.MAIL, process.env.PASS, process.env.RECEIVER, "Привет");