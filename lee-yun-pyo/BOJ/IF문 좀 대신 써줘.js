// 이진탐색
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [N, M] = input[0].trim().split(" ").map(Number);
const names = input
  .slice(1, 1 + N)
  .map((i) => i.trim().split(" "))
  .reverse();
const powers = input
  .slice(1 + N)
  .map((i) => i.trim())
  .map(Number);
let obj = {}; // 칭호 및 상한선 object
names.map((v) => (obj[+v[1]] = v[0]));
const limits = Object.keys(obj); // 전투력 상한선 가져오기

let answer = [];
for (const power of powers) {
  const limit = binary_search(limits, power, 0, limits.length - 1);
  answer.push(obj[limit]);
}
console.log(answer.join("\n"));

function binary_search(array, target, start, end) {
  let result = 0;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (array[mid] >= target) {
      result = array[mid];
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return result;
}
