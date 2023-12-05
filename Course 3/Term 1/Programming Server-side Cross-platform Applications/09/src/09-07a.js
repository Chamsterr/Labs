const rpcWSC = WebSocket = require('rpc-websockets').Client;
const readline = require('readline');

let ws = new rpcWSC('ws://localhost:4000');

ws.on('open',()=>{
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.on('line', (input) => {
        switch(input.toUpperCase()) {
            case 'A':
                ws.notify('A', {event: 'A'});
                break;
            case 'B':
                ws.notify('B', {event: 'B'});
                break;
            case 'C':
                ws.notify('C', {event: 'C'});
                break;
            default:
                console.log(`Unknown event: ${input}`);
        }
    });
})
