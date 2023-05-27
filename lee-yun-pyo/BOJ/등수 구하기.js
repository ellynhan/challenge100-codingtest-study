const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N, score, P], arr] = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((i) => i.split(" ").map(Number));

let result = 0;
if (N === 0) result = 1;
else {
  if (N === P) {
    if (score > arr[arr.length - 1]) {
      arr.push(score);
      arr.sort((a, b) => b - a);
      result = arr.indexOf(score) + 1;
    } else {
      result = -1;
    }
  } else {
    arr.push(score);
    arr.sort((a, b) => b - a);
    result = arr.indexOf(score) + 1;
  }
}

console.log(result);
