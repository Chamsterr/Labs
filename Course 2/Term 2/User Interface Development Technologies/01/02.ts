export class Challenge {
    static solution(number: number) {
        let numbers = new Set<number>();
        let answer;
        for (let i=5; i < number; i += 5){
            numbers.add(i)
        }

        for (let i=3; i < number; i += 3){
            numbers.add(i)
        }

        numbers.forEach(element => {
           answer += number 
        });
    }
}

Challenge.solution(3)