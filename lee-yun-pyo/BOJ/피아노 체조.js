const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N], arr, [Q], ...testCase] = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));

let newArr = [];
arr[0] > arr[1] ? newArr.push(1) : newArr.push(0);

for (let i = 0; i < N; i++) {
  if (arr[i] > arr[i + 1]) newArr.push(1);
  else newArr.push(0);
}

for (let i = 0; i < N; i++) newArr[i + 1] += newArr[i];

let answer = [];
for (let i = 0; i < Q; i++) {
  const start = testCase[i][0];
  const end = testCase[i][1];
  const result = newArr[end - 1] - newArr[start - 1];
  answer.push(result);
}

console.log(answer.join("\n"));
