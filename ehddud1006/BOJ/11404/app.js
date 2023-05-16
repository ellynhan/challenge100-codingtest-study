const fs = require("fs");

BOJkey = false;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/11404/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const INF = Number.MAX_SAFE_INTEGER;
const [n] = input.pop();
const [m] = input.pop();

const d = Array.from({ length: 101 }, () => Array(101).fill(INF));

while (input.length > 0) {
  const [a, b, c] = input.pop();
  d[a][b] = Math.min(d[a][b], c);
}

for (let i = 1; i <= n; i++) d[i][i] = 0;
for (let k = 1; k <= n; k++)
  for (let i = 1; i <= n; i++)
    for (let j = 1; j <= n; j++)
      if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

let answer = "";
for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    if (d[i][j] === INF) answer += `0 `;
    else answer += `${d[i][j]} `;
  }
  answer += "\n";
}

console.log(answer);
