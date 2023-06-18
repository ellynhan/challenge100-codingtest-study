const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));

const [N, M] = input[0];
const array = input[1].sort((a, b) => a - b);
const testCase = input.slice(2);

let answer = [];
for (let i = 0; i < M; i++) {
  let start = 0;
  let end = array.length - 1;
  const startPoint = testCase[i][0];
  const endPoint = testCase[i][1];

  const r1 = binary_search_start(array, startPoint, start, end);
  const r2 = binary_search_end(array, endPoint, start, end);
  answer.push(r2 - r1 < 0 ? 0 : r2 - r1 + 1);
}

console.log(answer.join("\n"));

function binary_search_start(array, target, start, end) {
  let result = 0;
  if (target > array[end]) return 99999;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (array[mid] >= target) {
      end = mid - 1;
      result = mid;
    } else start = mid + 1;
  }
  return result;
}

function binary_search_end(array, target, start, end) {
  let result = 0;
  if (target < array[start]) return -99999;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (array[mid] <= target) {
      start = mid + 1;
      result = mid;
    } else end = mid - 1;
  }
  return result;
}
