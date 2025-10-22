const send = require('m05_knv2')
require('dotenv').config({ path: '../.env' });

send(process.env.MAIL, process.env.PASS, process.env.RECEIVER, "Привет");   
 