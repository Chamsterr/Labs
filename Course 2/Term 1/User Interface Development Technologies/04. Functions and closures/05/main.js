function makeCounter() {
    let currentCount = 1;
    return function () {
        return currentCount++;
    };
}
let currentCount = 1;
function makeCounter1() {
    return function () {
        return currentCount++;
    };
}
alert(`
    1 - ${makeCounter.name}
    2 - ${makeCounter1.name}
`);