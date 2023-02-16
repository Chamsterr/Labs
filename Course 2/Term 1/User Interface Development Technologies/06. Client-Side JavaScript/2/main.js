// Класс Product должен позволять:
// - добавлять товар на страницу;
// - удалять конкретный товар (например, по коду);
// - устанавливать изображение товара (ссылку на изображение можно передавать в качестве параметры метода);
// - устанавливать название товара;
// - устанавливать стоимость товара;


let products = [];

class Product {
    constructor(name, price, img) {
        this.name = name;
        this.price = price;
        this.img = img;
        products.push(this);
    }
    deleteProduct(i) {
        products.splice(i, 1);
        delete this;
    }
}

function DeleteProductByName(name) {
    for (let i = 0; i < products.length; i++) {
        if (name == products[i].name) {
            products[i].deleteProduct(i);
        }
    }
}

product1 = new Product('Air', 100, 'nok600.jpg');

product2 = new Product('Ne Air', 1000, 'nok600.jpg');

product3 = new Product('Norm Air Pro', 10000, 'nok600.jpg');


function generateCatalog() {
    let catalog = document.getElementById('catalog');
    catalog.innerHTML = ''
    for (let i = 0; i < products.length; i++) {
        catalog.innerHTML +=
            `
            <div class="item">
                <img src="${products[i].img}" alt="" width="250px">
                <h1>${products[i].name}</h1>
                <p>${products[i].price}</p>
                ${new Button('В корзину', '75px', "white", '25px', '#0d6efd').createButton().outerHTML}
            </div>
        `
    }
}
// DeleteProductByName('Air');

// Для создания кнопок разработайте класс Button, который позволяет:
// - создать, удалить кнопку;
// - устанавливать размеры кнопки;
// - устанавливать фон кнопки;
// - устанавливать текст кнопки.

class Button {
    constructor(text, width, color, height, background) {
        this.text = text;
        this.width = width;
        this.color = color;
        this.height = height;
        this.background = background;
    }
    createButton() {
        let button = document.createElement('button');
        button.style.width = this.width;
        button.style.height = this.height;
        button.style.color = this.color;
        button.style.background = this.background;
        button.innerHTML = this.text;
        return button;
    }
}


generateCatalog()
// DeleteButtonById(1)

// function DeleteButtonById(Id) {
//     let buttonss = document.querySelectorAll('button');
//     buttonss[Id].remove();
// }

// function UpdateOddBackgroundById(color) {
//     let products = document.querySelectorAll('.item');
//     for (let i = 1; i < products.length; i += 2) {
//         products[i].style.background = color;
//     }
// }

UpdateOddBackgroundById("blue") 