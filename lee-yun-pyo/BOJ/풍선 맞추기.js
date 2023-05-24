const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N], array] = require("fs")
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.split(" ").map(Number));

let values = [];

for (let i = 0; i < N; i++) {
  if (values.includes(array[i] + 1)) {
    const index = values.indexOf(array[i] + 1);
    values[index] = array[i];
  } else {
    values.push(array[i]);
  }
}

console.log(values.length);
