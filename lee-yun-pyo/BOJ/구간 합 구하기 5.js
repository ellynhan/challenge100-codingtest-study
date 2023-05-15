const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N, M], ...input] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((i) => i.split(" ").map(Number));

const arr = input.slice(0, N);
let newArr = [];
for (const element of arr) {
  let tempArr = [element[0]];
  for (let i = 1; i < N; i++) {
    tempArr[i] = element[i] + tempArr[i - 1];
  }
  newArr.push(tempArr);
}
const objects = input.slice(N);

let result = "";
for (const element of objects) {
  let sum = 0;
  const [startX, startY] = [element[0], element[1]];
  const [endX, endY] = [element[2], element[3]];
  for (let i = startX - 1; i <= endX - 1; i++) {
    if (startY === 1) sum += newArr[i][endY - 1];
    else sum += newArr[i][endY - 1] - newArr[i][startY - 2];
  }
  result += sum.toString() + "\n";
}

console.log(result);
