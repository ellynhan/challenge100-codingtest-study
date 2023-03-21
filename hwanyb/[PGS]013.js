function solution(n) {
    return [...n.toString()].reduce((a, b) => Number(a) + Number(b), 0);
}