const async = require('async');
const rpcWSC = WebSocket = require('rpc-websockets').Client;

let ws = new rpcWSC('ws://localhost:4000');

let h = () => async.waterfall([
    cb => ws.call('square', [3]).then(r => cb(null, r)).catch(e => cb(e, null)),
    (p, cb) => ws.call('square', [5, 4]).then(r => cb(null, [p, r])).catch(e => cb(e, null)),
    (p, cb) => ws.call('mul', [3, 5, 7, 9, 11, 13]).then(r => cb(null, [r, p[0], p[1]])).catch(e => cb(e, null)),
    (p, cb) => ws.call('sum', [p[0], p[1], p[2]]).then(r => cb(null, r)).catch(e => cb(e, null)),
    (p, cb) => ws.login({login: 'admin', password: '+'}).then(login => login ? ws.call('fib', [7]) : null).then(r => cb(null, r + p)).catch(e => cb(e, null)),
    (p, cb) => ws.call('mul', [2, 4, 6]).then(r => cb(null, r * p)).catch(e => cb(e, null))
], (e, r) => {
    if (e) console.log(`e: `, e);
    else console.log(`r: `, r);
    ws.close();
});

ws.on('open', h);