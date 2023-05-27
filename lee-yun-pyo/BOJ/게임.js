const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [X, Y] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(" ")
  .map(Number);

const winning = Math.floor((100 * Y) / X);
const start = X;
const end = X * 2;

const result = binary_search(winning, start, end);
if (result === 0) console.log(-1);
else console.log(result - X);

function binary_search(winning, start, end) {
  let mid = 0;
  let max = 0;
  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    const midWinning = Math.floor((100 * (Y + mid - X)) / mid);
    if (midWinning > winning) {
      max = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return max;
}
