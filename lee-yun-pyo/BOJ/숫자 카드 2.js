const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [array, targets] = [
  input[1].split(" ").map(Number),
  input[3].split(" ").map(Number),
];

const haveCardMap = new Map();
for (const card of array) {
  if (haveCardMap.has(card)) {
    haveCardMap.set(card, haveCardMap.get(card) + 1);
  } else {
    haveCardMap.set(card, 1);
  }
}

let result = [];
for (const target of targets) {
  if (!haveCardMap.has(target)) result.push(0);
  else result.push(haveCardMap.get(target));
}

console.log(result.join(" "));
