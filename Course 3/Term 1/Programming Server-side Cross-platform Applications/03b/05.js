function square(n) {
    return new Promise((resolve, reject) => {
        if (typeof n !== 'number') {
            reject('Invalid input 1');
        } else {
            resolve(Math.pow(n, 2));
        }
    });
}

function cube(n) {
    return new Promise((resolve, reject) => {
        if (typeof n !== 'number') {
            reject('Invalid input 2');
        } else {
            resolve(Math.pow(n, 3));
        }
    });
}

function fourthPower(n) {
    return new Promise((resolve, reject) => {
        if (typeof n !== 'number') {
            reject('Invalid input 3');
        } else {
            resolve(Math.pow(n, 4));
        }
    });
}

Promise.all([square(2), cube(2), fourthPower(2)])
    .then(values => console.log(values))
    .catch(error => console.error(error));

Promise.all([square('two'), cube(2), fourthPower(2)])
    .then(values => console.log(values))
    .catch(error => console.error(error));

