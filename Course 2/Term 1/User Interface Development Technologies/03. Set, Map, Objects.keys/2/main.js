days = {
    "1": "ПН",
    "2": "ВТ",
    "3": "CР",
    "4": "ЧТ",
    "5": "ПТ",
    "6": "СБ",
    "7": "ВС"
}

function GetDay() {
    let guess;
    do {
        guess = prompt("Введите номер дня недели");
    } while (guess > 7 || guess < 0);
    return days[guess]
}

alert(GetDay())

function GetOddDays() {
    let text = "";
    let keys = Object.keys(days);
    let counter = 0;

    for (let i = 0; i < keys.length; i++) {
        console.log(1)
        if (Number(keys[i]) % 2 != 0) {
            text += `${keys[i]} - ${days[keys[i]]}\n`
            counter++;
        }
    }
    text += `Всего нечетных дней - ${counter}`;
    return text
}

alert(GetOddDays())

