function solution(cipher, code) {
    let answer = cipher[code - 1];
    for (let i = 2; i <= cipher.length / code; i++) {
        answer = answer + cipher[code * i - 1];
    }
    return answer;
}