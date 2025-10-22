function secondJob() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            reject('Hello World');
        }, 2000);
    });
}

secondJob().then((message) => {
    console.log('Promise handlers: ' + message);
}).catch((error) => {
    console.error('Promise handlers error: ' + error);
});

async function handleSecondJob() {
    try {
        const message = await secondJob();
        console.log('Async/await: ' + message);
    } catch (error) {
        console.error('Async/await error: ' + error);
    }
}

handleSecondJob();