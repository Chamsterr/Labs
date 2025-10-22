function firstJob() {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve('Hello World');
        }, 2000);
    });
}

firstJob().then((message) => {
    console.log('Promise handlers: ' + message);
}).catch((error) => {
    console.error('Promise handlers error: ' + error);
});

async function handleFirstJob() {
    try {
        const message = await firstJob();
        console.log('Async/await: ' + message);
    } catch (error) {
        console.error('Async/await error: ' + error);
    }
}

handleFirstJob();