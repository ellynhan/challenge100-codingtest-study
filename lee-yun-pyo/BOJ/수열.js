const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N, K], arr] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((i) => i.split(" ").map(Number));

let sum = 0;
let sum_arr = [];

for (let i = 0; i < N - K + 1; i++) {
  for (let j = 0; j < K; j++) {
    sum += arr[i + j];
  }
  sum_arr.push(sum);
  sum = 0;
}

console.log(Math.max(...sum_arr));
