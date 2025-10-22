let regexForCardNumber = /^(\d{4}-){3}\d{4}$|^(\d{4} ){3}\d{4}$|^\d{16}$/;
const { v4: uuidv4 } = require('uuid');

function validateCard(cardNumber){
    if (!regexForCardNumber.test(cardNumber)){
        return false
    }
    return Math.round(Math.random())
}

function createOrder(cardNumber){
    return new Promise((resolve, reject) => {
        console.log(`Card number: ${cardNumber}`)
        if (validateCard(cardNumber)){
            reject("Card is not valid")
        }
        else{
            let id = uuidv4();
            setTimeout(() => {handleProceedToPayment(id)}, 1000)
        }
    })
}

function proceedToPayment(id){
    return new Promise((resolve, reject) => {
        console.log(`Order ID: ${id}`)
        if(Math.round(Math.random())){
            resolve("Payment successfull")
        }
        else{
            reject("Payment failed")
        }
    })
}

async function handleProceedToPayment(id){
    try {
        const message = await proceedToPayment(id);
        console.log(message);
    } catch (error) {
        console.error(error);
    }
}

async function handleCreateOrder(cardNumber) {
    try {
        const message = await createOrder(cardNumber);
        console.log(message);
    } catch (error) {
        console.error('error: ' + error);
    }
}


// handleCreateOrder("5678 1224 1114 5678");


createOrder('2674 5478 6734 5678').then((orderNumber) => {return createOrder(orderNumber);})
                                  .then((paymentResult) => {console.log(paymentResult);})
                                  .catch((error) => {console.error(error);});