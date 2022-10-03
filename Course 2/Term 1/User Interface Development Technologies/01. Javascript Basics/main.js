//---------------------1---------------------
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
//else{
//  alert(pow(x, n));  
//}

//---------------------2---------------------
let userName = 'Chamster';
let city = 'Minsk';
const BIRTHDAY = 2004;
const REDCOLOR = '#f00';
let userAnswer;
let inf = Infinity;
let number = 532;
let perimeter = '120mm';
let message = 'Введенные данные неверны';

//---------------------3---------------------
// let a = 5;
// let name = "Name";
// let i = 0;
// let double = 0.23;
// let result = 1/0;
// let answer = true;
// let no = null;

//---------------------4---------------------
function getArea(firstRectangelSide, secondRectangelSide){
    return firstRectangelSide * secondRectangelSide;
}

//---------------------5---------------------

function howManySquare(firstRectangelSide, secondRectangelSide, square){
    return Math.floor(firstRectangelSide * secondRectangelSide / square);
}

//---------------------6---------------------
let i = 2;
let a = ++i;
let b = i++;

//---------------------7--------------------
console.log('Привет' < 'привет');
console.log('Привет' > 'Пока');
console.log(45 < '53');
console.log(false < 3);

console.log(3 > '5мм');

console.log(null < undefined);

//---------------------8---------------------
function checkPassphrase(){
    phrase = prompt('Введите секретную фразу', '');
    let passPhrase = 'ясекретнаяфраза';
    if (phrase.toLowerCase() == passPhrase){
        alert('Норм');
    }
    else{
        alert('не норм');
    }
}
//---------------------9---------------------

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
//---------------------10---------------------
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
//---------------------11---------------------
function getSum(){
    let a = prompt('Введите число а: ');
    let b = prompt('Введите число b: ');
    alert(Number(a) + Number(b));
}
//---------------------12--------------------
// console.log(true + true)
// console.log(0 + "5")
// console.log(5 + "мм")
// console.log(8 / Infinity)
// console.log(9 * "\n9")
// console.log(null - 1)
// console.log("5" - 2)
// console.log("5px" - 3)
// console.log(true - 3)
// console.log(0 || 7)

//---------------------13---------------------
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
//---------------------14---------------------
function neponaytnoChto2(x){
    while (x <= 100){
        x = prompt('Введите x')
    }
}
//---------------------15---------------------

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

//---------------------4---------------------
console.log(getArea(45, 21));

//---------------------5---------------------
console.log(howManySquare(45, 21, 5));

//---------------------8---------------------
// checkPassphrase();

//---------------------9---------------------
// loginValidation();

//---------------------10--------------------
examResultsCheck();

//---------------------11--------------------
// getSum();

//---------------------13--------------------
// neponaytnoChto();

//---------------------14--------------------
// neponaytnoChto2(`${prompt('Введите x')}`)

//---------------------14--------------------
// getDay()