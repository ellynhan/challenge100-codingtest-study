const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const [H, W] = input[0].split(" ").map((v) => +v);
const arr = input[1].split(" ").map((v) => +v);

let answer = 0;
for (let i = 1; i < arr.length; i++) {
  let left = -1;
  let right = -1;
  let min = 0;
  let result = 0;

  for (let j = i; j >= 0; j--) left = Math.max(arr[j], left);

  for (let j = i; j < W; j++) right = Math.max(arr[j], right);

  min = Math.min(left, right);
  result += min - arr[i];
  answer += result;
}

console.log(answer);
