function f(...arguments) {
    if (arguments.length <= 3) {
        return arguments.join(" ")
    }
    else if (arguments.length > 3 && arguments.length <= 5) {
        return arguments.map(x => typeof x);
    }
    else if (arguments.length > 5 && arguments.length <= 7) {
        return arguments.length
    }
    else {
        return "количество аргументов очень большое"
    }
}

console.log(f('Привет', 'мир!'))
console.log(f(1, "1", "1", ""))
console.log(f("1", "1", "1", "", "1", "1"))
console.log(f("1", "1", "1", "", "1", "1", "1", "1"))