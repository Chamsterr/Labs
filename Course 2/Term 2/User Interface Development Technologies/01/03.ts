function sdwigArray(arr: Array<number>, num: number): Array<number> {
    return arr.slice(-num).concat(arr.slice(0, arr.length - num))
}

console.log(sdwigArray([1, 2, 3, 4, 5, 6], 1))