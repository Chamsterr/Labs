const rpcWSC = WebSocket = require('rpc-websockets').Client;
const async = require('async');

const ws = new rpcWSC('ws://localhost:4000');

ws.on('open', () => {
    const calls = [
        { method: 'square', params: [3], protected: false },
        { method: 'square', params: [5, 4], protected: false },
        { method: 'sum', params: [2], protected: false },
        { method: 'sum', params: [2, 4, 6, 8, 10], protected: false },
        { method: 'mul', params: [3], protected: false },
        { method: 'mul', params: [3, 5, 7, 9, 11, 13], protected: false },
        { method: 'fib', params: [1], protected: true },
        { method: 'fib', params: [2], protected: true },
        { method: 'fib', params: [7], protected: true },
        { method: 'fact', params: [0], protected: true },
        { method: 'fact', params: [5], protected: true },
        { method: 'fact', params: [10], protected: true }
    ];

    const handleCall = (call) => {
        ws.call(call.method, call.params)
            .then(res => console.log(`method: ${call.method} | params: ${call.params} | res: ${res}`))
            .catch(e => console.log(e));
    };


    let tasks = [];

    calls.forEach(call => {
        tasks.push((callback) => {
            if (call.protected) {
                ws.login({ login: 'admin', password: '+' })
                    .then((login) => {
                        if (login) {
                            handleCall(call);
                        }
                        callback(null);
                    })
                    .catch((e) => {
                        console.log('Login failed', e);
                        callback(e);
                    });
            } else {
                handleCall(call);
                callback(null);
            }
        });
    });

    async.parallel(tasks, (err, results) => {
        if (err) {
            console.log('An error occurred:', err);
        } else {
            console.log('All calls completed successfully');
        }
    });
});

ws.on('error', (e) => console.log('error = ', e));
