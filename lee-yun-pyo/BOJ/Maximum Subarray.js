// dp
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

let answer = [];
const T = +input.splice(0, 1);
for (let i = 0; i < T; i++) {
  const N = +input.splice(0, 1);
  const inputArr = input.splice(0, 1).join().trim().split(" ").map(Number);
  const arr = [0, ...inputArr];
  answer.push(solution(N, arr));
}

console.log(answer.join("\n"));

function solution(N, arr) {
  const dp = Array.from({ length: N + 1 }, () => 0);
  for (let i = 1; i <= N; i++) {
    dp[i] = Math.max(dp[i - 1], arr[i - 1], 0) + arr[i];
  }
  return Math.max(...dp.slice(1));
}
