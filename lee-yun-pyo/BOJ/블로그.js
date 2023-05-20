const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const [N, X] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

let sumArr = [0];
for (const element of arr) {
  sumArr.push(sumArr[sumArr.length - 1] + element);
}

let resultArr = [];
if (sumArr[sumArr.length - 1] === 0) console.log("SAD");
else {
  for (let i = 0; i < N - X + 1; i++) {
    const result = sumArr[i + X] - sumArr[i];
    resultArr.push(result);
  }
  const max = Math.max(...resultArr);
  const count = resultArr.filter((i) => i === max).length;
  console.log(max);
  console.log(count);
}
