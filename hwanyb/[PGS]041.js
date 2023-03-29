function solution(array) {
    return array.sort((a, b) => a - b)[Math.ceil(array.length / 2 - 1)];
}