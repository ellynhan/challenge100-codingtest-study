const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = require("fs").readFileSync(filePath).toString().trim();

let [[N, M], arr, ...testCase] = input
  .split("\n")
  .map((v) => v.split(" ").map((i) => +i));

for (let i = 1; i < N; i++) {
  arr[i] = arr[i - 1] + arr[i];
}

let result = "";
for (const element of testCase) {
  const [start, end] = element;
  start - 2 < 0
    ? (result += arr[end - 1] - 0)
    : (result += arr[end - 1] - arr[start - 2]);
  result += "\n";
}

console.log(result.trim());
