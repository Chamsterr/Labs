function createPhoneNumber(arr) {
    return arr.length == 10 ?
        "(".concat(arr.slice(0, 3).join(""), ") ").concat(arr.slice(3, 6).join(""), "-").concat(arr.slice(6).join(""))
        : "Wrong phone number";
}

console.log(createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]));
