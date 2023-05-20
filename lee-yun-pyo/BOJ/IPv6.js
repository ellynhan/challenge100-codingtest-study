const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().trim().split(":");
const LENGTH = 8;

let answer = "";
const zero_arr = ["", "0", "00", "000", "0000"];
for (let i = 0; i < input.length; i++) {
  if (input[i].length === 0) {
    answer += ":";
    continue;
  } else if (input[i].length !== 4) {
    answer += zero_arr[4 - input[i].length] + input[i];
  } else {
    answer += input[i];
  }
  answer += ":";
}

answer = answer.slice(0, -1);
const arr = answer.split(":");
let zeros = "";
const blank = arr.filter((i) => i === "").length;
if (blank > 0) {
  if (blank === 3) {
    for (let i = 0; i < LENGTH; i++) {
      zeros += ":0000";
    }
  } else if (blank === 2) {
    for (let i = 0; i < LENGTH - (arr.length - 2); i++) {
      zeros += ":0000";
    }
    zeros += ":";
  } else {
    for (let i = 0; i < LENGTH - (arr.length - 1); i++) {
      zeros += ":0000";
    }
    zeros += ":";
  }
}

answer = answer.replace("::", zeros);
if (answer[0] === ":") answer = answer.slice(1);
if (answer[answer.length - 1] === ":") answer = answer.slice(0, -1);

console.log(answer);
