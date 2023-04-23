const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const T = +input[0];
const newArr = input.slice(1);
for (let i = 1; i < T * 2; i += 2) {
  let deque = []; // 결과 값 가져오기 위한 배열
  const arr = newArr[i]
    .split(" ")
    .map((v) => +v)
    .sort((a, b) => b - a);

  for (let j = 0; j < arr.length; j++) {
    if (j % 2 === 0) deque.push(arr[j]);
    else deque.unshift(arr[j]);
  }

  let result = 0;
  for (let i = 0; i < deque.length; i++) {
    let diff = 0;
    if (i === deque.length - 1) diff = Math.abs(deque[i] - deque[0]);
    diff = Math.abs(deque[i] - deque[i + 1]);
    if (result < diff) result = diff;
  }

  console.log(result);
}
