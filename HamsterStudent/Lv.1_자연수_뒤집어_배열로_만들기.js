function solution(n) {
    var answer = String(n).split('').reverse();
    return answer.map((x)=> Number(x));
}
