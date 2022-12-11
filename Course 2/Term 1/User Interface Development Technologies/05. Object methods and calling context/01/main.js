let products = {

};

products[Symbol.iterator] = function () {
    return {
        next() {
            if (this.current === undefined) {
                this.current = 1
            }

            if (this.current <= Object.keys(products).length) {
                return {
                    done: false,
                    value: products[Object.keys(products)[this.current]]
                }
            }
            else {
                delete this.current;
                return {
                    done: true
                };
            }
        }
    }
}

function Product(id, name, category, price, size, color, discount = 1) {
    Object.defineProperty(this, 'id', {
        value: id,
        writable: false,
    });

    this.name = name
    this.category = category

    Object.defineProperty(this, "price", {
        value: price,
        writable: false
    });

    Object.defineProperty(this, 'size', {
        value: size,
        writable: false
    })

    Object.defineProperty(this, 'color', {
        value: color,
        writable: false
    })
    this.discount = discount

    Object.defineProperty(this, 'totalPrice', {
        get: function () {
            return this.price - this.price * this.discount / 100;
        },
        set: function (value) {
            this.discount = (this.price - value) / this.price * 100;
        }
    });
}


product1 = new Product(1, "Норм кросы", "кросы", 12321, 43, "black")
product2 = new Product(2, "Норм боты", "боты", 12000, 42, "brown")
product3 = new Product(3, "Норм сандали", "сандали", 12500, 42, "black")

products[product1.name] = product1
products[product2.name] = product2
products[product3.name] = product3


let priceee = products[product1.name].totalPrice;
console.log(priceee)

let all = document.querySelector("#ul_products");
let counter = 0;
for (product in products) {
    console.log(++counter)
    console.log(products.length)
    all.innerHTML += `<li>${products[product].id}) ${products[product].name} price - ${products[product].totalPrice} color - ${products[product].color} size - ${products[product].size}</li>`
}

let filter = document.querySelector('#ul_filter_products');

let price = document.querySelector('#price')
price.oninput = function () {
    filterGenerator()
}

let color = document.querySelector('#color')
color.oninput = function () {
    filterGenerator()
}

let size = document.querySelector('#size')
size.oninput = function () {
    filterGenerator()
}

function filterGenerator() {
    let price = document.querySelector('#price')
    let filterPrice = price.value.split('-')

    let color = document.querySelector('#color')
    let filterColor = color.value

    let size = document.querySelector('#size')
    let filterSize = size.value
    filter.innerHTML = ""

    for (product in products) {
        let result = ""
        if (!(filterPrice[0] == "" && filterSize == "" && filterColor == "")) {
            if ((filterPrice[0] == "" || (Number(filterPrice[0]) <= products[product].totalPrice && Number(filterPrice[1]) >= products[product].totalPrice)) && (filterSize == "" || products[product].size == filterSize) && (filterColor == "" || products[product].color == filterColor)) {
                result += `<li>${products[product].id}) ${products[product].name} price - ${products[product].totalPrice} color - ${products[product].color} size - ${products[product].size}</li>`;
            }
        }
        filter.innerHTML += result
    }
}