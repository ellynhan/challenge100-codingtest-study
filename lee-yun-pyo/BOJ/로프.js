const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const arr = input
  .slice(1)
  .map(Number)
  .sort((a, b) => b - a);

let max_value = arr[0];

for (let i = 1; i < arr.length; i++) {
  const value = arr[i] * (i + 1);
  if (max_value < value) max_value = value;
}

console.log(max_value);
