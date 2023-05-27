const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [M, N] = input[0].split(" ").map(Number);
const array = input[1].split(" ").map(Number);

const start = 1;
const end = Math.max(...array);

const answer = binary_search(array, start, end);
console.log(answer);

function binary_search(array, start, end) {
  let result = 0;
  while (start <= end) {
    let sum = 0;
    const mid = Math.floor((start + end) / 2);
    for (let i = 0; i < N; i++) {
      if (array[i] >= mid) {
        sum += Math.floor(array[i] / mid);
      }
    }
    if (sum >= M) {
      result = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    sum = 0;
  }
  return result;
}
