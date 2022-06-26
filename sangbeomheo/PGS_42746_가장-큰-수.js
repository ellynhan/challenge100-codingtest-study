// https://programmers.co.kr/learn/courses/30/lessons/42746

function solution(numbers) {
  if (numbers.reduce((a, b) => a + b) == 0) return "0";

  return numbers
    .map((number) => `${number}`)
    .sort((a, b) => b + a - (a + b))
    .join("");
}

console.log(solution([6, 10, 2])); // 6210
console.log(solution([0, 0, 0, 0])); // 0
console.log(solution([3, 30, 34, 5, 9])); // 9534330
