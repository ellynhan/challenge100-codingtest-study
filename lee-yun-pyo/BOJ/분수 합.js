const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim())
  .map((i) => i.split(" ").map((k) => +k));
// input: [ [ 2, 7 ], [ 3, 5 ] ]

function init(input) {
  const x = input[0][1]; // 분모1
  const xPrime = input[0][0]; // 분자1
  const y = input[1][1]; // 분모2
  const yPrime = input[1][0]; // 분자2
  let result = [];
  result = [xPrime * y + yPrime * x, x * y];
  const gcd = GCD(result[0], result[1]);
  if (gcd > 1) {
    console.log(result[0] / gcd, result[1] / gcd);
  } else {
    console.log(result[0], result[1]);
  }
}

init(input);

function GCD(p, q) {
  if (q === 0) return p;
  return GCD(q, p % q);
}
