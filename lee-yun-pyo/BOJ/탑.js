const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().trim().split("\n");

const arr = input[1].split(" ").map(Number);

let stack = [[arr[0], 1]];
let index = 0;
let result = [0];
for (let i = 1; i < arr.length; i++) {
  if (arr[i] <= stack[index][0]) {
    stack.push([arr[i], i + 1]);
    result.push(stack[index][1]);
    index = stack.length - 1;
  } else {
    /* 기준 값보다 큰 값이 나올 때까지 작은 값들 제거 */
    while (index >= 1 && stack[index--][0] < arr[i]) {
      stack.pop();
    }
    stack.push([arr[i], i + 1]);
    index = stack.length - 1;
    if (index >= 1 && stack[index][0] <= stack[index - 1][0])
      result.push(stack[index - 1][1]);
    else result.push(0);
  }
}

console.log(result.join(" "));
