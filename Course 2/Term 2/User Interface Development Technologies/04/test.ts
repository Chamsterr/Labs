let numbers: number[] = new Array(7, 5, 3, 0, 9, 6, 1, 8, 2, 4);
PhoneNumber(numbers);

function PhoneNumber(numb: number[]) {
    let phonenumb = "";
    for (let i = 0; i < 10; i++) {
        if (i == 0) {
            phonenumb += "(" + numb[i];
        }
        else if (i == 3) {
            phonenumb += ") " + numb[i];
        }
        else if (i == 6) {
            phonenumb += "-" + numb[i];
        }
        else {
            phonenumb += numb[i];
        }
    }
    console.log(phonenumb);
}

ReturnMultiples(18);
function ReturnMultiples(num: number) {
    let correctvalues = new Set<number>()
    for (let i = 1; i < num; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            correctvalues.add(i);
            console.log(correctvalues);
        }
    }

    let sum = 0;

    for (let correctvalue of correctvalues) {
        sum += correctvalue;
        console.log(correctvalue);
    }
    console.log("Sum of number: " + sum);
}