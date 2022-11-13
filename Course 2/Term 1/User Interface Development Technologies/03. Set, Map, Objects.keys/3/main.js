let button = {
    "min-height": "50px",
    "min-width": "150px",
    "border-radius": "15px"
}

let special = {
    "background": "yellow"
}

let bShow = document.querySelectorAll("button")
let styleForButtons = ""
let keys = Object.keys(button);
let style = "";
for (let j = 0; j < keys.length; j++) {
    style += `${keys[j]}:${button[keys[j]]}; \n`
}

console.log(1, style)

but.style.cssText = `${style}`