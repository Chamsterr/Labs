function changeBgImg() {
    let images = {
        0: "url(img/dog1.jpg)",
        1: "url(img/dog.jpg)",
        2: "url(img/dog2.jpg)"
    }

    let guess = Math.floor(Math.random() * 3)

    document.body.style.backgroundImage = images[guess]
    console.log(guess)
}

function PrintComments() {
    let id = document.querySelector("#comment")

    keys = Object.keys(localStorage)

    keys.sort()

    if (keys.length == 0) {
        id.innerHTML = `<p class="no-comments">Комментариев пока нет</p>`
    }
    for (let i = 0; i < keys.length; i++) {
        id.innerHTML += `<div> <p> <span class="username">${JSON.parse(localStorage.getItem(keys[i])).username}</span> <span class="date">${keys[i]}</span>  <br> <span class="text">${JSON.parse(localStorage.getItem(keys[i])).text}</span><hr> </p></div>`
    }
}

function Checker(text) {
    text = text.replaceAll("кот", "***")
    text = text.replaceAll("кош", "***")
    text = text.replaceAll("Кот", "***")
    text = text.replaceAll("Кош", "***")

    text = text.replaceAll("пес", "многоуважаемый пес")
    text = text.replaceAll("собак", "Cобак")
    return text
}

function addComment() {
    let form = document.forms[0];
    let maxSize = 50;
    let username = form.elements.username.value;
    let text = form.elements.text.value;

    if (text.length >= maxSize) {
        alert(`Комментарий превышает максимальную длину - ${maxSize}!`)
        return false
    }
    else if (text.length == 0) {
        alert(`Вы забыли написать комментарий...`)
        return false
    }
    username = Checker(username)
    text = Checker(text)

    let comment = {
        username: username,
        text: text
    }

    let now = new Date();
    localStorage.setItem(String(now).split(' ').slice(1, 5).join(' '), JSON.stringify(comment))

}
changeBgImg()
PrintComments()