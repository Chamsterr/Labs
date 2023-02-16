let bigCube = {
    width: '50px',
    height: '50px',
    border: '1px solid black',
    "background-color": 'yellow'
}

let whiteCircle = {
    width: '50px',
    height: '50px',
    border: '1px solid black',
    "background-color": 'white'
}

let whiteTriangleWithVerticalLine = {
    width: '50px',
    height: '50px',
    countOfVerticalLines: 1,
}

let tinyCube = {
    width: '20px',
    height: '20px',
    border: '1px solid black',
    "background-color": 'yellow'
}

let greenCircle = {
    width: '50px',
    height: '50px',
    border: '1px solid black',
    background: 'green'
}

let whiteTriangleWithVerticalLines = {
    width: '50px',
    height: '50px',
    countOfVerticalLines: 3
}

function CircleDifference() {
    const propsOne = Object.getOwnPropertyNames(whiteCircle); 
    const propsTwo = Object.getOwnPropertyNames(greenCircle);

    for(let counter = 0; counter < propsOne.length; counter++){
        if(whiteCircle[propsOne[counter]] != greenCircle[propsTwo[counter]]){
            console.log(propsOne[counter] + ' : ' + whiteCircle[propsOne[counter]] + ' - ' + greenCircle[propsTwo[counter]]);
        }
    }
}

CircleDifference()

function PrintPropertis(obj){
    const properties = Object.getOwnPropertyNames(obj); 
    for(let counter = 0; counter < properties.length; counter++){
        console.log(properties[counter] + ' : ' + obj[properties[counter]]);
    }
}

PrintPropertis(whiteTriangleWithVerticalLines)

function CheckBGcolor(obj){
    console.log(obj.hasOwnProperty("background-color"))
}

CheckBGcolor(tinyCube)