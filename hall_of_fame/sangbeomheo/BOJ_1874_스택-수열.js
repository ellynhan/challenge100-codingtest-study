/*

백준 / 스택 수열 / 실버 2
https://www.acmicpc.net/problem/1874

< 소요 시간 >
48분

*/

const [n, ...arr] = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

input = arr.map((value) => +value);
const stack = [];
let number = 1;
let answer = "";

for (let i = 0; i < n; i++) {
  while (input[i] >= number) {
    stack.push(number);
    answer += "+ ";
    number++;
  }

  if (input[i] !== stack.pop()) {
    answer = "NO";
    break;
  }
  answer += "- ";
}

console.log(answer.split(" ").join("\n"));
