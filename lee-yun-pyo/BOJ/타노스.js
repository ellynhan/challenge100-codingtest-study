const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = require("fs").readFileSync(filePath).toString().trim().split("");

const one = input.filter((i) => i === "1").length / 2;
const zero = input.filter((i) => i === "0").length / 2;

let [oneCount, zeroCount] = [0, 0];
let [i, j] = [0, input.length - 1];
while (true) {
  if (oneCount === one) break;
  if (input[i] === "1") {
    input[i] = "";
    oneCount += 1;
  }
  i++;
}
while (true) {
  if (zeroCount === zero) break;
  if (input[j] === "0") {
    input[j] = "";
    zeroCount += 1;
  }
  j--;
}

console.log(input.join(""));
