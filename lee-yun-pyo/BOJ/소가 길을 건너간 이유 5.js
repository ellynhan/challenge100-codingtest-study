const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [input, ...inputArr] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [N, K, B] = input.split(" ").map(Number);
const repaired = inputArr.map(Number);

const array = new Array(N).fill(1);
for (const element of repaired) {
  array[element - 1] = 0;
}

let window = array.slice(0, K).reduce((ac, cv) => ac + cv, 0);
let answer = K - window;
for (let i = K; i < N; i++) {
  window += array[i] - array[i - K];
  if (K - window < answer) answer = K - window;
}

console.log(answer);
