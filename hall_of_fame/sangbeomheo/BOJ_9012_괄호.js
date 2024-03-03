/*

백준 / 괄호 / 실버 4
https://www.acmicpc.net/problem/9012

< 소요 시간 >
16분

< 프로그래밍 계획 >

  1. 괄호가 ) 일 때 스택이 (면 패스 & 스택 제거
  2. 괄호가 ( 일 때 스택이 (면 패스
  3. 1,2가 아닌 경우는 "NO"
  4. 스택의 길이가 0이 아니면 "NO"
  5. 아니면 "YES"

*/

const [n, ...arr] = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

console.log(arr.map((line) => vailateBrackets(line)).join("\n"));

function vailateBrackets(brackets) {
  let result = "YES";
  const stack = [];

  for (const bracket of brackets) {
    const endBracket = stack[stack.length - 1];

    if (bracket === ")" && endBracket === "(") {
      stack.pop();
    } else if (bracket === "(" && endBracket !== ")") {
      stack.push(bracket);
    } else {
      result = "NO";
      break;
    }
  }

  if (stack.length !== 0) result = "NO";

  return result;
}
