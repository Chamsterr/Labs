class Product {
    get totalPrice() {
        return this.price - this.price * this.discount / 100;
    }
    constructor(id, name, category, size, color, price, discount = 0) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.size = size;
        this.color = color;
        this.price = price;
        this.discount = discount;
    }
    getCategory() {
        return this.category;
    }
}
class ProductStore {
    constructor() {
        this.products = {
            boots: [],
            sneakers: [],
            sandals: []
        };
    }
    addShoe(product) {
        switch (product.getCategory()) {
            case 'Ботинки':
                this.products.boots.push(product);
                break;
            case 'Кроссовки':
                this.products.sneakers.push(product);
                break;
            case 'Сандали':
                this.products.sandals.push(product);
                break;
        }
    }
    getProductsBySize(size) {
        let filteredProducts = new Array;
        for (let shoe of this) {
            if (shoe.size == size) {
                filteredProducts.push(shoe);
            }
        }
        return filteredProducts;
    }
    getProductsByColor(color) {
        let filteredProducts = new Array;
        for (let shoe of this) {
            if (shoe.color.toUpperCase() == color.toUpperCase()) {
                filteredProducts.push(shoe);
            }
        }
        return filteredProducts;
    }
    getProductsByPrice(price) {
        let filteredProducts = new Array;
        let distance = price.split('-').map(str => Number(str));
        for (let shoe of this) {
            console.log(shoe.price >= distance[0] && shoe.price <= distance[1]);
            if (shoe.totalPrice >= distance[0] && shoe.totalPrice <= distance[1]) {
                filteredProducts.push(shoe);
            }
        }
        return filteredProducts;
    }
    filterGenerator() {
        filter.innerHTML = "";
        let filteredByPrice = price.value ? this.getProductsByPrice(price.value) : [...this];
        let filteredByColor = color.value ? this.getProductsByColor(color.value) : [...this];
        let filteredBySize = size.value ? this.getProductsBySize(Number(size.value)) : [...this];
        let result = filteredByPrice.filter(p => filteredByColor.includes(p)).filter(p => filteredBySize.includes(p));
        for (let product of result) {
            filter.innerHTML += `<li>${product.id}) ${product.name} price - ${Math.round(product.totalPrice)} color - ${product.color} size - ${product.size}</li>`;
        }
    }
    *[Symbol.iterator]() {
        for (let shoe of this.products.boots) {
            yield shoe;
        }
        for (let shoe of this.products.sneakers) {
            yield shoe;
        }
        for (let shoe of this.products.sandals) {
            yield shoe;
        }
    }
}
let store = new ProductStore();
store.addShoe(new Product(1, "Норм кроссы", "Ботинки", 15, "Black", 1101));
store.addShoe(new Product(2, "Удобные тапки", "Сандали", 8, "White", 1235));
store.addShoe(new Product(3, "Красивые кроссовки", "Кроссовки", 20, "Brown", 6232, 80));
store.addShoe(new Product(4, "Стильные кроссовки", "Кроссовки", 12, "Black", 9732));
store.addShoe(new Product(5, "Уютные ботинки", "Ботинки", 18, "Gray", 1534));
for (let shoe of store) {
    console.log(`Категория: ${shoe.getCategory()}`);
}
let all = document.querySelector("#ul_products");
for (let shoe of store) {
    all.innerHTML += `<li>${shoe.id}) ${shoe.name} price - ${Math.round(shoe.totalPrice)} color - ${shoe.color} size - ${shoe.size}</li>`;
}
let filter = document.querySelector('#ul_filter_products');
let price = document.querySelector('#price');
let color = document.querySelector('#color');
let size = document.querySelector('#size');
store.filterGenerator();
color.oninput = function () {
    store.filterGenerator();
};
size.oninput = function () {
    store.filterGenerator();
};
price.oninput = function () {
    store.filterGenerator();
};