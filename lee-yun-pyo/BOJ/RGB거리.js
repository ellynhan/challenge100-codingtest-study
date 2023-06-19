const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const N = +input[0];
let array = input.slice(1).map((i) => i.split(" ").map(Number));

for (let i = 1; i < N; i++) {
  for (let j = 0; j < 3; j++) {
    const filterArray = array[i - 1].filter((v, idx) => idx !== j);
    array[i][j] = Math.min(...filterArray) + array[i][j];
  }
}

console.log(Math.min(...array[N - 1]));
