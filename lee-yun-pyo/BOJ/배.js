const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));

const [N, M] = [input[0][0], input[2][0]];
const max_weight = input[1].sort((a, b) => b - a);
const box_weight = input[3].sort((a, b) => b - a);

const answer = solution(max_weight, box_weight);
console.log(answer);

function solution(max_weight, box_weight) {
  let result = -1;
  if (max_weight[0] < box_weight[0]) return result;

  let time = 0;
  let i = 0;
  let j = 0;
  while (box_weight.length !== 0) {
    if (i === N || j === box_weight.length) {
      i = 0;
      j = 0;
      time++;
    } else if (max_weight[i] >= box_weight[j]) {
      i++;
      box_weight.splice(j, 1);
    } else if (max_weight[i] < box_weight[j]) {
      j++;
    }
  }

  result = time + 1;
  return result;
}
