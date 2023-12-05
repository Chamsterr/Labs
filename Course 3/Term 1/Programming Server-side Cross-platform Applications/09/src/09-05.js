const rpcWSS = require('rpc-websockets').Server;

const server = new rpcWSS({
    port: 4000, 
    host: 'localhost'
});

server.setAuth(loginDetails => {
    return loginDetails.login === 'admin' && loginDetails.password === '+';
});

const operations = {
    square: (args) => {
        if (args.length === 1) {
            const [r] = args;
            return Math.PI * r * r;
        } else if (args.length === 2) {
            const [a, b] = args;
            return a * b;
        }
    },
    sum: (args) => args.reduce((a, b) => a + b, 0),
    mul: (args) => args.reduce((a, b) => a * b, 1),
    fib: (args) => {
        const sequence = [0, 1];
        for (let i = 2; i < args; i++) {
            sequence.push(sequence[i - 1] + sequence[i - 2]);
        }
        return sequence[sequence.length - 1];
    },
    fact: (args) => {
        let result = 1;
        for (let i = 2; i <= args; i++) {
            result *= i;
        }
        return result;
    }
};

Object.entries(operations).forEach(([name, func]) => {
    server.register(name, func).public();
});