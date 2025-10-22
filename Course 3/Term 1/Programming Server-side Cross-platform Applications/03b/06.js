function square(n) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof n !== 'number') {
                reject('Invalid input');
            } else {
                resolve(Math.pow(n, 2));
            }
        }, 1000);
    });
}

function cube(n) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof n !== 'number') {
                reject('Invalid input');
            } else {
                resolve(Math.pow(n, 3));
            }
        }, 2000);
    });
}

function fourthPower(n) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof n !== 'number') {
                reject('Invalid input');
            } else {
                resolve(Math.pow(n, 4));
            }
        }, 3000);
    });
}

Promise.race([square("123sa"), cube(2), fourthPower(2)])
    .then(value => console.log(value))
    .catch(error => console.error(error));

Promise.any([square(2), cube(2), fourthPower(2)])
    .then(value => console.log(value))
    .catch(error => console.error(error));