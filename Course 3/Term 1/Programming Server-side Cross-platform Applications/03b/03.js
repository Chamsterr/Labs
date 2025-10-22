function thirdJob(data){
    return new Promise((resolve, reject) => {
        if (typeof data !== "number"){
            reject("error")
        }
        else if(data % 2 != 0){
            setTimeout(() => {
                resolve("odd")
            }, 1000)
        }
        else{
            setTimeout(() => {
                resolve("even")
            }, 2000)
        }
    })
}

thirdJob(1).then((message) => {
    console.log('Promise handlers: ' + message);
}).catch((error) => {
    console.error('Promise handlers error: ' + error);
});
thirdJob(2).then((message) => {
    console.log('Promise handlers: ' + message);
}).catch((error) => {
    console.error('Promise handlers error: ' + error);
});


async function handleThirdJob(data) {
    try {
        const message = await thirdJob(data);
        console.log('Async/await: ' + message);
    } catch (error) {
        console.error('Async/await error: ' + error);
    }
}

handleThirdJob("123s");
handleThirdJob(1);