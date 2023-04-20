const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs.readFileSync(filePath).toString().trim().split("").sort();

let counts = [];
const set = new Set(input);
const myArr = [...set];
let onlyOne = "";
set.forEach((item) => counts.push(input.filter((i) => i === item).length));
const countOfOdd = counts.filter((i) => i % 2 !== 0).length;
if (countOfOdd >= 2) {
  console.log("I'm Sorry Hansoo");
  return;
}
if (countOfOdd === 1) {
  const oddValue = counts.filter((i) => i % 2 !== 0);
  const index = counts.indexOf(oddValue[0]);
  const inputIndex = input.indexOf(myArr[index]);
  onlyOne = input.splice(inputIndex, 1);
}

let [front, back] = [[], []];
for (let i = 0; i < input.length; i += 2) {
  front.push(input[i]);
  back.unshift(input[i]);
}

if (onlyOne) console.log(front.join("") + onlyOne[0] + back.join(""));
else console.log(front.join("") + back.join(""));
