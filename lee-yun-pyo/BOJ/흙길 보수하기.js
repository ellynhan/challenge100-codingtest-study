// 정렬, 스위핑
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [N, L] = input.splice(0, 1).join().split(" ").map(Number);
const inputArr = input
  .map((i) => i.split(" ").map(Number))
  .sort((a, b) => a[0] - b[0]);

let temp = 0;
let answer = 0;
for (let i = 0; i < N; i++) {
  let [start, end] = inputArr[i];
  if (temp >= start) start = temp + 1;
  const count = Math.ceil((end - start) / L);
  temp = start - 1 + count * L;
  answer += count;
}

console.log(answer);
