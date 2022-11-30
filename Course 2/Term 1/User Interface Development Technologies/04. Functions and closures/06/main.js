function figureVolume(a) {
    return b => {
        return c => {
            return a * b * c
        }
    }
}

console.log(figureVolume(1)(2)(3))

const rebro = figureVolume(2);
console.log(rebro(1)(12))