const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [input1, input2] = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const [N, M] = input1.split(" ").map((i) => +i);
const books = input2.split(" ").map((v) => +v);

let negative_location = [0]; // 음수 위치
let positive_location = [0]; // 양수 위치
// 0 원소를 넣은 이유: 24~25행에서 변수 값이 undefined 되는 것 방지

books.forEach((element) => {
  if (element > 0) positive_location.push(element);
  else negative_location.push(element);
});

negative_location.sort((a, b) => b - a);
positive_location.sort((a, b) => a - b);

const nBigNum = Math.abs(negative_location[negative_location.length - 1]);
const pBigNum = positive_location[positive_location.length - 1];

let result = 0;
if (nBigNum > pBigNum) {
  negative_location.splice(-M);
  result += nBigNum;
} else {
  positive_location.splice(-M);
  result += pBigNum;
}

while (negative_location.length !== 0 || positive_location.length !== 0) {
  const nRemoved = negative_location.splice(-M);
  const pRemoved = positive_location.splice(-M);
  if (nRemoved.length > 0) {
    const nValue = Math.abs(nRemoved[nRemoved.length - 1]);
    result += nValue * 2;
  }
  if (pRemoved.length > 0) {
    const pValue = pRemoved[pRemoved.length - 1];
    result += pValue * 2;
  }
}

console.log(result);
