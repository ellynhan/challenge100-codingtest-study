const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [S, T] = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

while (true) {
  if (T[T.length - 1] === "A") {
    T = T.slice(0, -1);
  } else {
    T = T.slice(0, -1);
    T = T.split("").reverse().join("");
  }
  if (T === S) {
    console.log(1);
    return;
  }
  if (T.length < S.length) {
    console.log(0);
    return;
  }
}
