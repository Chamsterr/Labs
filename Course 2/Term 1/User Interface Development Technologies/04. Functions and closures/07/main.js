let x = 0;
let y = 0;

function* fff(direction) {
    if (direction == 'right') {
        x += 10;
    }
    else if (direction == 'left') {
        x -= 10;
    }
    else if (direction == 'up') {
        y += 10;
    }
    else if (direction == 'down') {
        y -= 10;
    }
    yield [x, y]
}


let ff = fff();

while (true) {
    let direction = prompt('Введите направление');
    if (direction == 'stop') {
        break;
    }
    alert(fff(direction).next().value)
}