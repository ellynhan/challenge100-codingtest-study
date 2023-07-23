const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const N = +input[0];
const arr = input.slice(1).map(Number);

const dp = Array.from(new Array(N + 1));

dp[1] = arr[0];
dp[2] = dp[1] + arr[1];
dp[3] = Math.max(arr[0], arr[1]) + arr[2];
for (let i = 4; i <= N; i++) {
  dp[i] = Math.max(dp[i - 3] + arr[i - 2] + arr[i - 1], dp[i - 2] + arr[i - 1]);
}

console.log(dp[N]);
