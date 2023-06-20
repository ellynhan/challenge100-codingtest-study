const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const arr = input[1].split(" ").map(Number);

function solution(arr) {
  if (arr.length === 1) return 1;
  const dp = Array.from({ length: arr.length }, () => 1);

  for (let i = 1; i < arr.length; i++) {
    let cnt = 0;
    for (let j = 0; j < i; j++) {
      if (arr[i] > arr[j]) cnt = Math.max(cnt, dp[j]);
    }
    dp[i] += cnt;
  }
  return Math.max(...dp);
}

console.log(solution(arr));
