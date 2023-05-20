const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().trim().split("\n");

let answer = 0;
const N = +input[0];
const arr = input.slice(1).map((i) => i.split(" ").map((v) => +v));

arr.sort((a, b) => a[0] - b[0]);
const sticks = arr.map((i) => i[1]);
const max = Math.max(...sticks);
const maxList = arr.filter((i) => i[1] === max);

/* max 기준 왼쪽 값들 계산 */
let stack = [{ x: arr[0][0], length: arr[0][1] }];
let result = [];
for (let i = 1; i < N; i++) {
  if (stack[stack.length - 1].length < arr[i][1]) {
    const temp = stack.pop();
    result.push(temp);
    stack.push({ x: arr[i][0], length: arr[i][1] });
  }
}
result.push({ x: maxList[0][0], length: maxList[0][1] });

for (let i = 0; i < result.length - 1; i++) {
  const w = result[i + 1].x - result[i].x;
  const h = result[i].length;
  answer += w * h;
}

/* max 기준 오른쪽 값 계산 */
const reverseArr = arr.reverse();
stack = [{ x: reverseArr[0][0], length: reverseArr[0][1] }];
result = [];
for (let i = 1; i < N; i++) {
  if (stack[stack.length - 1].length < reverseArr[i][1]) {
    const temp = stack.pop();
    result.push(temp);
    stack.push({ x: reverseArr[i][0], length: reverseArr[i][1] });
  }
}
result.push({
  x: maxList[maxList.length - 1][0],
  length: maxList[maxList.length - 1][1],
});

for (let i = 0; i < result.length - 1; i++) {
  const w = result[i].x - result[i + 1].x;
  const h = result[i].length;
  answer += w * h;
}

/* 높이가 max인 범위 계산 */
const maxW = maxList[maxList.length - 1][0] - maxList[0][0] + 1;
const maxH = maxList[0][1];
answer += maxW * maxH;

console.log(answer);
