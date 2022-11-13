let list = new Set();

function generateHTML() {
    let ul = document.getElementById('list');
    ul.innerHTML = ""
    for (let it of list) {
        ul.innerHTML += `<li>${it}</li>`
    }

    let text = document.getElementById('text')
    text.innerHTML = `Всего: ${list.size}`
}

function addFunction() {
    let item = prompt("Введите название товара");

    if (item != null && item != "") {
        item = item[0].toUpperCase() + item.slice(1)
        list.add(item);
        generateHTML()
    }
}
function deleteItem() {
    let item = prompt("Введите название товара");
    list.delete(item);

    generateHTML()
}

function searchFunction() {
    let liTags = document.getElementsByTagName("li");
    let item = prompt("Что хотите найти?")
    let found;

    for (var i = 0; i < liTags.length; i++) {
        if (liTags[i].textContent.toLowerCase() == item.toLowerCase()) {
            found = liTags[i];
            liTags[i].style.color = "yellow"
            break;
        }
    }
}