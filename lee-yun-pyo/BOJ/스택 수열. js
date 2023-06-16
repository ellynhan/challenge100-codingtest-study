const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [N, ...arr] = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map(Number);

let stack = [];
let result = [];
let num = 1;
let j = 0;
let isNo = false;
while (j < N) {
  if (stack[stack.length - 1] !== arr[j]) {
    if (num > N) {
      isNo = true;
      break;
    }
    stack.push(num++);
    result.push("+");
  } else {
    stack.pop();
    result.push("-");
    j++;
  }
}

console.log(isNo ? "NO" : result.join("\n"));
