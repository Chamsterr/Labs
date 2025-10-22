require('dotenv').config({ path: '../.env' });

const send = require('m05_knv2')

send(process.env.MAIL, process.env.PASS, process.env.RECEIVER, "Привет");