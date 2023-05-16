const fs = require("fs");

BOJkey = false;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/11780/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const INF = Number.MAX_SAFE_INTEGER;
const [n] = input.pop();
const [m] = input.pop();

const d = Array.from({ length: 101 }, () => Array(101).fill(INF));
const nxt = Array.from({ length: 101 }, () => Array(101).fill(INF));

while (input.length > 0) {
  const [a, b, c] = input.pop();
  d[a][b] = Math.min(d[a][b], c);
  nxt[a][b] = b;
}

for (let i = 1; i <= n; i++) d[i][i] = 0;
for (let k = 1; k <= n; k++)
  for (let i = 1; i <= n; i++)
    for (let j = 1; j <= n; j++)
      if (d[i][k] + d[k][j] < d[i][j]) {
        d[i][j] = d[i][k] + d[k][j];
        nxt[i][j] = nxt[i][k];
      }

let answer = "";
for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    if (d[i][j] === INF) answer += `0 `;
    else answer += `${d[i][j]} `;
  }
  answer += "\n";
}

for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= n; j++) {
    let target = nxt[i][j];
    if (target === INF) answer += "0\n";
    else {
      let count = 2;
      let tempString = "";
      tempString += `${target} `;
      while (target !== j) {
        target = nxt[target][j];
        tempString += `${target} `;
        count++;
      }
      tempString = `${count} ${i} ${tempString}\n`;
      answer += tempString;
    }
  }
}

console.log(answer);
