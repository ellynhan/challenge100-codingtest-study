const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

const N = +input[0];
const tasks = input
  .slice(1)
  .map((i) => i.split(" ").map((v) => +v))
  .sort((a, b) => a[1] - b[1]);

const hasToEndTimes = tasks.map((i) => i[1]); // [ 5, 14, 16, 20 ]

let endTimes = []; // [ 3, 11, 12, 17 ]
let sum = 0;
for (let i = 0; i < N; i++) {
  sum += tasks[i][0];
  endTimes.push(sum);
}

let result = -1;
while (true) {
  for (let i = 0; i < N; i++) {
    if (endTimes[i] > hasToEndTimes[i]) {
      console.log(result);
      return;
    }
  }
  result++;
  endTimes = endTimes.map((i) => i + 1);
}
