const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 4000 });

let messageNumber = 0;

wss.on('connection', ws => {
    let client;
    ws.on('message', data => {console.log('on message: ', JSON.parse(data));

    client = JSON.parse(data).client});
    
    let k = 0;

    setInterval(()=>{
        ws.send(JSON.stringify(
            {
                server:++k,
                client: client,
                timestamp: Date.now()
            }))
    }, 5000);

});