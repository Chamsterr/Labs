let list = new Map();

list.set(
    "Ноутбук", {
    "id": "1",
    "number": 1,
    "price": 15_000
})

list.set(
    "Телефон", {
    "id": "2",
    "number": 1,
    "price": 1_000
})

list.set(
    "Машина", {
    "id": "3",
    "number": 1,
    "price": 1_000_000
})


let cart = new Map();

function htmlGenerator() {
    let ul = document.getElementById('list');
    ul.innerHTML = ""
    for (let it of list) {
        ul.innerHTML += `<li onclick="transfer(this.innerText)">id.${it[1]["id"]} ${it[0]} ${it[1]["price"]}$</li>`
    }

    ul = document.getElementById('cart');
    ul.innerHTML = ""
    let sum = 0
    let numbers = 0
    for (let it of cart) {
        numbers += it[1]["number"]
        sum += it[1]["price"] * it[1]["number"];
        ul.innerHTML += `<li onclick="deleteFromCart(this.innerText)">id.${it[1]["id"]} ${it[0]} ${it[1]["price"]}$ x${it[1]["number"]}</li>`
    }

    span = document.getElementById('total');
    span.innerHTML = `${sum}$ x${numbers}`;

}
function transfer(string) {
    console.log(string)
    let item = string.split(' ')[1];
    console.log(item)
    if (!cart.has(item)) {
        let text = Object.assign({}, list.get(item));
        cart.set(item, text)
    }
    else {
        console.log("Я тут")
        let number = cart.get(item)["number"];
        number++;
        cart.get(item)["number"] = number
    }
    htmlGenerator()
}

function deleteFromCart(string) {
    let item = string.split(' ')[1];
    let number = cart.get(item)["number"];
    console.log(number)
    if (number == 1) {
        cart.delete(item)
    }
    else {
        number--;
        cart.get(item)["number"] = number
        console.log(cart)
    }
    htmlGenerator()
}

htmlGenerator()