function solution(array) {
    return [Math.max(...array), array.indexOf(Math.max(...array))];
}