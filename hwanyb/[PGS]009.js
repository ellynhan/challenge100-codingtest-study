function solution(n, t) {
    return new Array(t).fill(n).reduce((a, b) => a * 2, n);
}