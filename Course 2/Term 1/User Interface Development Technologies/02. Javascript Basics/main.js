// function getSquareDiameterLengthCircle(){
//     const pi = 3.1415926;
//     let radius = prompt('Введите радиус окружности');

//     alert(`Длина окружности - ${2*pi*radius} \nПлощадь окружности - ${pi*radius**2} \nДиаметр окружности - ${radius*2}`);
// }

// getSquareDiameterLengthCircle()

// function userMessage(){
//     let sum = 0;
//     let userMoney = 3;
//     let productPrice = 1;

//     while(productPrice > 0){
//         productPrice = prompt('Введите цену товара')
//         if ((sum + Number(productPrice)) > userMoney){
//             alert('Недостаточно средств на балансе\nВыберите другой товар или завершите покупку')
//         }
//         else{
//             sum += Number(productPrice)
//         }
//     }

//     return sum
// }

// alert(userMessage())

// function concatStrings(firstString, lastString, space = ' '){
//     return firstString + space + lastString
// }

// let firstString = prompt('Введите первую строку:')
// let lastString = prompt('Введите последнию строку:')

// alert(concatStrings(firstString, lastString))

function counterOfStudents(){
    let student = 1;
    while (student){
        let counter = 0;
        student = prompt(`${counter++} Имя и фамилия`)
    }
    return counter;
}

counterOfStudents()