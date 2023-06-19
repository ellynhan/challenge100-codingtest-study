const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const N = +input[0];
let array = input.slice(1).map((i) => i.split(" ").map(Number));

for (let i = N - 1; i > 0; i--) {
  for (let j = 0; j < array[i - 1].length; j++) {
    array[i - 1][j] = Math.max(array[i][j], array[i][j + 1]) + array[i - 1][j];
  }
}

console.log(array[0][0]);
