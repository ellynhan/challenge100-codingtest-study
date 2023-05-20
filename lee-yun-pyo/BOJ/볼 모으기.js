const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().split("\n");
const N = +input[0];
const arr = input[1];
let count = 0;
let entire = [];
let type = arr[0];
for (let i = 0; i < N; i++) {
  if (arr[i] === "R") {
    if (type === "B" && count > 0) {
      entire.push({ type, count });
      count = 0;
      type = "R";
    }
    count++;
  } else {
    if (type === "R" && count > 0) {
      entire.push({ type, count });
      count = 0;
      type = "B";
    }
    count++;
  }
  if (i === N - 1) {
    if (type !== arr[i]) {
      entire.push({ type: type === "R" ? "B" : "R", count: 1 });
    } else {
      entire.push({ type, count });
    }
  }
}

function solution(entire) {
  let result = 0;
  let [B_arr, R_arr] = [[], []];
  let [B_sum, R_sum] = [0, 0];
  if (entire[0].type === entire[entire.length - 1].type) {
    const type = entire[0].type;
    const firstValue = entire[0].count;
    const lastValue = entire[entire.length - 1].count;
    if (type === "R") {
      B_arr = entire.filter((e) => e.type === "B");
      R_arr = entire.slice(1, -1).filter((e) => e.type === "R");
      B_sum = B_arr.reduce((ac, cv) => ac + cv.count, 0);
      R_sum = R_arr.reduce((ac, cv) => ac + cv.count, 0);
      R_sum = firstValue > lastValue ? R_sum + lastValue : R_sum + firstValue;
    } else {
      R_arr = entire.filter((e) => e.type === "R");
      B_arr = entire.slice(1, -1).filter((e) => e.type === "B");
      R_sum = R_arr.reduce((ac, cv) => ac + cv.count, 0);
      B_sum = B_arr.reduce((ac, cv) => ac + cv.count, 0);
      B_sum = firstValue > lastValue ? B_sum + lastValue : B_sum + firstValue;
    }
  } else {
    B_arr = entire.slice(1, -1).filter((e) => e.type === "B");
    R_arr = entire.slice(1, -1).filter((e) => e.type === "R");
    B_sum = B_arr.reduce((ac, cv) => ac + cv.count, 0);
    R_sum = R_arr.reduce((ac, cv) => ac + cv.count, 0);
  }
  result = B_sum > R_sum ? R_sum : B_sum;
  console.log(result);
}

solution(entire);
