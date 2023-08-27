const isCorrect: boolean = true;
const isUncorrect: boolean = false;
const int: number = 42;
const float: number = 4.2
const num: number = 3e10
const message: string = "Hello World";
// -----------------------------

// arrays
const numberArray: number[] = [1, 2, 3, 4, 5, 6]
const numberArray2: Array<number> = [1, 2, 3, 4, 5, 6]
const words: string[] = ['Hello', 'World']
// ------------------------------

// Tuple
const contact: [string, number] = ['Nikita', 123123213]
// ------------------------------

// Any
let variable: any = 42
variable = "String"
// ------------------------------

// Functions
function Print(word: string): void{
    console.log(word)
}

Print("W");

// Never
function throwError(message: string): never {
    throw new Error(message);
}

function infiniteLoop(): never {
    while (true) {
      // do something
    }
}
// ------------------------------

// Type 
type Login = string;
const login: Login = 'admin';
// const login2: Login = 2; 

type ID = string | number
const id1: ID = 1234
const id2: ID = "1234"
// const id3: ID = true;

type SomeType = string | null | undefined
// ------------------------------