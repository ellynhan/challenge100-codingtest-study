const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((v) => v.trim())
  .map((i) => i.split(" ").map((j) => +j));

const lengthOfTape = input[0][1];
const location = input[1].sort((a, b) => a - b);
let result = 0;
let index = 0;
let initialValue = location[index];

while (index != -1) {
  let temp = initialValue + lengthOfTape - 1;
  index = location.findIndex((v) => v > temp);
  initialValue = location[index];
  result++;
}

console.log(result);
