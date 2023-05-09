const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const T = +input[0];

const inputArr = input.slice(1);
for (let i = 0; i < T * 2; i += 2) {
  const str = inputArr[i];
  const K = +inputArr[i + 1];
  const words = Array.from(new Set(str));
  let candidates = {};
  let lenList = [];

  for (let word of words) {
    let temp = [];
    for (let i = 0; i < str.length; i++) {
      if (word === str[i]) temp.push(i);
    }
    if (temp.length >= K) candidates[word] = temp;
  }

  if (!Object.keys(candidates).length) {
    console.log(-1);
  } else {
    for (let key in candidates) {
      const current = candidates[key];
      if (current.length === K) {
        const firstValue = current[0];
        const lastValue = current[current.length - 1];
        lenList.push(lastValue - firstValue + 1);
      } else {
        for (let j = 0; j < current.length - K + 1; j++) {
          lenList.push(current[j + K - 1] - current[j] + 1);
        }
      }
    }
    console.log(`${Math.min(...lenList)} ${Math.max(...lenList)}`);
  }
}
