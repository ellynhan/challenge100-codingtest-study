const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const N = +input[0];
const inputArr = input.slice(1).map((v) => v.split(" ").map(Number));
let x = inputArr.map((v) => v[0]).sort((a, b) => a - b);
let y = inputArr.map((v) => v[1]).sort((a, b) => a - b);
const x_mid = x[Math.floor(N / 2)];
const y_mid = y[Math.floor(N / 2)];

let result = 0;
for (let i = 0; i < N; i++) {
  result += Math.abs(x_mid - x[i]) + Math.abs(y_mid - y[i]);
}

console.log(result);
