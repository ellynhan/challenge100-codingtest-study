function solution(quiz) {
    let answerArr = new Array(quiz.length);
    for (let i = 0; i < quiz.length; i++) {
        let num1 = Number(quiz[i].split(' ')[0]);
        let num2 = Number(quiz[i].split(' ')[2]);
        let answer = Number(quiz[i].split(' ')[4]);

        if (quiz[i].split(' ')[1] === "+") {
            let realAnswer = num1 + num2;

            if (realAnswer == answer) {
                answerArr[i] = "O";
            } else {
                answerArr[i] = "X";
            }
        } else {
            let realAnswer = num1 - num2;
            if (realAnswer == answer) {
                answerArr[i] = "O";
            } else {
                answerArr[i] = "X";
            }
        }
    }
    return answerArr;
}