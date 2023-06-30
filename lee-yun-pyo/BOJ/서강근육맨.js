const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];
const array = input[1].split(" ").map((v) => BigInt(v));
array.sort((a, b) => (a < b ? -1 : 1));

let result = 0n;
if (N % 2 === 0) {
  result = array[0] + array[N - 1];
  for (let i = 1; i < Math.floor(N / 2); i++) {
    const temp = array[i] + array[N - 1 - i];
    if (temp > result) result = temp;
  }
} else {
  result = array[N - 1];
  for (let i = 0; i < Math.floor(N / 2); i++) {
    const temp = array[i] + array[N - 2 - i];
    if (temp > result) result = temp;
  }
}

console.log(String(result));
