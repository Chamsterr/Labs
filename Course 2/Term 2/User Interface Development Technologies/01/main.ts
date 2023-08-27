function createPhoneNumber(arr: Array<number>) : string{
    return arr.length == 10 ? 
        `(${arr.slice(0,3).join("")}) ${arr.slice(3,6).join("")}-${arr.slice(6).join("")}`
        :"Wrong phone number"
}