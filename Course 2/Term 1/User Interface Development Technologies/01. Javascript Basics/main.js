// function hello(name) {
//     let phrase = `Hello, ${name}!`;
    
//     say(phrase);
// }

// function say(phrase) {
//     alert(`** ${phrase} **`)
// }

// function pow(x, n){
//     let result = 1;
//     for (var i = 0; i < n; i++){
//         result *= x;
//     }
//     return result;
// }

// x = prompt('x?', '');
// x = prompt('n?', '');

// if (n < 0){
//     alert(`Cтепень ${n} не поддерживается, введите целую степень, большую 0`);
// }

//---------------------------------------------

let userName = 'Chamster';
let city = 'Minsk';
const BIRTHDAY = 2004;
const REDCOLOR = '#f00';
let userAnswer;
let inf = Infinity;
let number = 532;
let perimeter = '120mm';
let message = 'Введенные данные неверны';

// //---------------------------------------------
function getArea(firstRectangelSide, secondRectangelSide){
    return firstRectangelSide * secondRectangelSide;
}

// //---------------------------------------------

function howManySquare(firstRectangelSide, secondRectangelSide, square){
    return Math.floor(firstRectangelSide * secondRectangelSide / square);
}


// //---------------------------------------------
function checkPassphrase(){
    phrase = prompt('Введите секретную фразу', '');
    let passPhrase = 'ясекретнаяфраза';
    if (String(phrase).toLowerCase() == passPhrase){
        alert('Норм');
    }
    else{
        alert('не норм');
    }
}
// //---------------------------------------------

function loginValidation(){
    let adminLogin = 'admin';
    let adminPassword = 1;

    login = prompt('Введите login:', '')
    password = prompt('Введите password:', '')

    if (adminLogin == login.toLowerCase() && adminPassword == password){
        alert('Вход успешно выполнен')
    }
    else{
        alert(message)
    }
}
// //----------------------------------------------
function examResultsCheck(){
    let math = prompt('Оценка по математике: ');
    let english = prompt('Оценка по английскому: ');
    let russian = prompt('Оценка по русскому: ');

    if ((Number(math) < 4 && Number(english) < 4 &&  Number(russian) < 4)){
        confetti({
            particleCount: 2000,
            spread: 160,
            origin: {
                y:0.9
            }
        });
        alert('Поздравляем, вас отчислили!');
    }
    else if (Number(math) < 4 || Number(english) < 4 ||  Number(russian) < 4){
        confetti({
            particleCount: 2000,
            spread: 160,
            origin: {
                y:0.9
            }
        });
        alert('Поздравляем, у вас как минимум одна пересдача!');
    }
    else {
        alert('Вы перешли на следующий курс')
    }
}
//--------------------------------------------
function getSum(){
    let a = prompt('Введите число а: ');
    let b = prompt('Введите число b: ');
    alert(Number(a) + Number(b));
}
//-------------------------------------------
function neponaytnoChto(){
    for (let x = 1; x <= 10; x++){
        if (checkParity(x)){
            console.log(x + 2)
        }
        else{
            console.log(x + 'mm')
        }
    }
}

function checkParity(number){
    if (number % 2 == 0){ return true }

    return false;
}
// //--------------------------------------------
function neponaytnoChto2(x){
    while (x < 100){
        x = prompt('Введите x')
    }
}
// //-------------------------------------------

function getDay(){
    let number = prompt("Введите день недели")
    switch(number){
        case '1':
            alert('Пн');
            break;
        case '2':
            alert('Вт');
            break;
        case '3':
            alert('Ср');
            break;
        case '4':
            alert('Чт');
            break;
        case '5':
            alert('Пт');
            break;
        case '6':
            alert('Сб');
            break;
        case '7':
            alert('Вс');
            break;
    }
}

// //-------------------------------------------
console.log(getArea(45, 21));
console.log(howManySquare(45, 21, 5));

// checkPassphrase();

// loginValidation();

// examResultsCheck();

// getSum();

// neponaytnoChto();

// neponaytnoChto2(`${prompt('Введите x')}`)

getDay()