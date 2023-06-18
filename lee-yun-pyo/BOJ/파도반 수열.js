const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const inputArr = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map(Number);

const N = inputArr[0];
const arr = inputArr.slice(1);

function solution(n, arr) {
  let result = [];
  let values = [0, 1, 1, 1, 2, 2];

  for (let i = 0; i < n; i++) {
    if (arr[i] >= 6) {
      for (let j = 6; j <= arr[i]; j++) {
        values[j] = values[j - 5] + values[j - 1];
      }
    }
    result.push(values[arr[i]]);
  }
  return result;
}

const answer = solution(N, arr);
console.log(answer.join("\n"));
