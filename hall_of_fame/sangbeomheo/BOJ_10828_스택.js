/*

백준 / 스택 / 실버 4
https://www.acmicpc.net/problem/10828

< 소요 시간 >
20분

< 프로그래밍 계획 >
- 배열로 스택 구현

*/
const [n, ...arr] = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const stack = [];
const answer = [];

arr.forEach((command) => {
  const [action, value] = command.split(" ");

  switch (action) {
    case "push":
      stack.push(value);
      break;

    case "pop":
      answer.push(stack.length ? stack.pop() : -1);
      break;

    case "top":
      answer.push(stack.length ? stack[stack.length - 1] : -1);
      break;

    case "size":
      answer.push(stack.length);
      break;

    case "empty":
      answer.push(stack.length ? 0 : 1);
      break;

    default:
      break;
  }
});

console.log(answer.join("\n"));
