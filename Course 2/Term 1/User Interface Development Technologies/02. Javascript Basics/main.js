//---------------------1---------------------
function getSquareDiameterLengthCircle(){
    const pi = 3.1415926;
    let radius = prompt('Введите радиус окружности');

    alert(`Длина окружности - ${2*pi*radius} \nПлощадь окружности - ${pi*radius**2} \nДиаметр окружности - ${radius*2}`);
}

let getSquareDiameterLengthCircleExpression = function() {
    const pi = 3.1415926;
    let radius = prompt('Введите радиус окружности');

    alert(`Длина окружности - ${2*pi*radius} \nПлощадь окружности - ${pi*radius**2} \nДиаметр окружности - ${radius*2}`);
}

let getSquareDiameterLengthCircleArrow = () =>{
    const pi = 3.1415926;
    let radius = prompt('Введите радиус окружности');
    alert(`Длина окружности - ${2*pi*radius} \nПлощадь окружности - ${pi*radius**2} \nДиаметр окружности - ${radius*2}`);
}

//---------------------2---------------------
// let firstString = prompt('Введите первую строку:')
// let lastString = prompt('Введите вторую строку:')

// let concatStrings = (firstString, secondString, space = ' ') => firstString + space + secondString

//---------------------3---------------------
function counterOfStudents(){
    
    let listOfStudents = [];
    let student = 1;
    let counter = 1;

    while (student){
        student = prompt(`${printListOfStudent(listOfStudents)}`)
        counter++;
        listOfStudents.push(student)
    }

    alert(`${text}Всего студентов - ${counter - 2}`)
}

function printListOfStudent(listOfStudents) {
    text = '';
    for (let x = 0 ; x < listOfStudents.length; x++){
        text += (`${x + 1}. ${listOfStudents[x]} \n`)
    }
    return text;
}

//---------------------4---------------------
function howMuchTime(){
    let amount = 26 * 26 * 26 * 26 * 26 * 10 * 10 * 10;

    const NumOfSecInY = 365 * 24 * 60 * 60;
    const NumOfSecInM = 30 * 24 * 60 * 60;
    const NumOfSecInD = 24 * 60 * 60;
    const NumOfSecInH = 60 * 60;
    const NumOfSecInMin = 60;

    let seconds = amount * 3;

    let years = Math.floor(seconds / NumOfSecInY);

    let months = Math.floor((seconds - years * NumOfSecInY) / NumOfSecInM);

    let days = Math.floor((seconds - years * NumOfSecInY - months * NumOfSecInM) 
                          / NumOfSecInD);

    let hours = Math.floor((seconds - years * NumOfSecInY - months * NumOfSecInM
        - days * NumOfSecInD) / NumOfSecInH);

    let minutes = Math.floor((seconds - years * NumOfSecInY - months * NumOfSecInM
        - days * NumOfSecInD - hours * NumOfSecInH)/ NumOfSecInMin);

    seconds = seconds - years * NumOfSecInY - months * NumOfSecInM
        - days * NumOfSecInD - hours * NumOfSecInH - minutes * NumOfSecInMin;

    alert(`${years} лет ${months} месяцев ${days} дней ${hours} часов ${minutes} минут ${seconds} секунд`)
}

//---------------------5---------------------
function func(){
    let data = prompt('Введите данные');

    if (Number(data)){
        alert(`Округление в меньшую сторону - ${parseFloat(Math.floor(data)).toString(16).toUpperCase()}\nОкругление в большую сторону - ${parseFloat(Math.ceil(data)).toString(16).toUpperCase()}\nОкругление до ближайшего целого - ${parseFloat(Math.round(data)).toString(16).toUpperCase()}\n`)
    }
    else{
        alert(`${data.toUpperCase()} \n${data.toLowerCase()}`)
    }

}

//---------------------6---------------------
function getMistakeIfExist(firstString, secondString) {
    for(let i = 0; i < firstString.length; i++){
        if (firstString[i] != secondString[i]){
            return (i + 1)
        }
    }
    return 0;
}

function checkCT(){
    const word = 'алгоритм';
    let userTry = prompt('Введите ваш вариант').toLowerCase();

    let Check = (mistakeIfExist = getMistakeIfExist(word, userTry)) ?
    () => alert(`Ошибка в позиции ${mistakeIfExist}`) :
    () => alert('Правильно');

    Check();
}

//---------------------7---------------------
function geometryCalculator(a, b){
    let c = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2))

    let sina = b/c
    let cosa = a/c
    let tga = b/a
    let ctga = a/b

    let sinb = a/c
    let cosb = b/c
    let tgb = a/b
    let ctgb = b/a

    let square = 0.5 * a * b
    let height = (2 * square) / c
    let perimeter = a + b + c


    alert(`sin(a) - ${sina} \ncos(a) - ${cosa} \ntg(a) - ${tga} \nctg(a) - ${ctga} \n\nsin(b) - ${sinb} \ncos(b) - ${cosb} \ntg(b) - ${tgb} \nctg(b) - ${ctgb}  \n\nПериметр - ${perimeter} \nПлощадь - ${square} \nВысота - ${height}`)
}

//---------------------1---------------------
// getSquareDiameterLengthCircle()
// getSquareDiameterLengthCircleExpression()
// getSquareDiameterLengthCircleArrow()

//---------------------2---------------------
// alert(concatStrings(firstString, lastString))

//---------------------3---------------------
// counterOfStudents()

//---------------------4---------------------
// howMuchTime();

//---------------------5---------------------
func()

//---------------------6---------------------
// checkCT()

//---------------------7---------------------
// geometryCalculator(4, 3)