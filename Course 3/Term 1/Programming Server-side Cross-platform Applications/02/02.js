var http = require("http")
var fs = require("fs")

const hostname = '127.0.0.1';
const port = 5000;


const server = http.createServer((req, res) => {
    const fname = "./02.jpg"
    let jpg = null

    fs.stat(fname, (err, stat) =>{
        if(err){console.log('error:', err)}
        else {
            jpg = fs.readFileSync(fname);
            res.writeHead(200, {"Content-Type": "image/jpeg", "Content-Lenght": `stat`.size})
            res.end(jpg, "binary")
        }
    })
});


server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});