// 소인수분해
function solution(n) {
    let answer = [];
    let divisor = 2;

    while (n >= 2) {
        if (n % divisor === 0) {
            answer.push(divisor);
            n /= divisor;
        }
        else {
            divisor++;
        }
    }
    return [...new Set(answer)];
}