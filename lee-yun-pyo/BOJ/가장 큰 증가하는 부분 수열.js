const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
let array = [0, ...input[1].split(" ").map(Number)];
const dp = Array.from({ length: N + 1 }, () => 0);

for (let i = 1; i <= N; i++) {
  for (let j = 0; j < i; j++) {
    if (array[i] > array[j]) dp[i] = Math.max(dp[i], dp[j] + array[i]);
  }
}

console.log(Math.max(...dp));
