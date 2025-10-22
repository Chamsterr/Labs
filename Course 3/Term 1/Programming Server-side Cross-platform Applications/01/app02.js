const http = require('http');
 
const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  let b = "";

  req.on("data", str => {
    b += (str);
    console.log("data", b);
  });
  
  const method = req.method;
  const uri = req.url;
  const protocolVersion = `${req.httpVersionMajor}.${req.httpVersionMinor}`;
  const headers = JSON.stringify(req.headers, null, 4);

  req.on("end", () => {
    const response = `
      <h1>Lab 01</h1>
      
      <ul style="padding: 0 0 0 0">
        <li>URI - ${uri}</li>
        <li>method - ${method}</li>
        <li>protocolVersion - ${protocolVersion}</li>
      </ul>
      <hr/>

      <h2>Headers</h2>
      <pre>${headers}</pre>
      <hr/>

      <h2>Body</h2>
      <p>${b}</p>
      <hr/>
    `;
    res.end(response);
  });
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});

