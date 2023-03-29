function solution(n) {
    if (n === 1) {
        return 0;
    }
    return Array.from({ length: n }, (_, i) => i + 1).filter(i => i % 2 === 0).reduce((a, b) => a + b);
}

// 생각지도 못한 풀이
function solution(n) {
    var half = Math.floor(n / 2);
    return half * (half + 1);
}