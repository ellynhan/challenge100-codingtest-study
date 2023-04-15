const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((v) => v.trim());

const K = +input[1];
const locations = input[2]
  .split(" ")
  .map((i) => +i)
  .sort((a, b) => a - b);

let gaps = [];
for (let i = 0; i < locations.length - 1; i++) {
  const gap = locations[i + 1] - locations[i];
  gaps.push(gap);
}

gaps.sort((a, b) => a - b);
const index = gaps.length - K + 1;

const result = gaps
  .slice(0, index)
  .reduce((prev, currentValue) => prev + currentValue, 0);

console.log(result);
