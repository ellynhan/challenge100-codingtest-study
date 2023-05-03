const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.trim());

let stack = [];
let i = 0;
while (true) {
  const arr = input[i].split("");
  if (arr[0] === "-") return;
  for (let j = 0; j < arr.length; j++) {
    stack.push(arr[j]);
    if (stack[stack.length - 1] === "}" && stack[stack.length - 2] === "{") {
      stack.splice(-2, 2);
    }
  }
  if (stack.every((current) => current === "{")) {
    console.log(`${i + 1}.`, stack.length / 2);
  } else if (stack.every((current) => current === "}")) {
    console.log(`${i + 1}.`, stack.length / 2);
  } else {
    const count1 = stack.filter((e) => e === "{").length;
    const count2 = stack.filter((e) => e === "}").length;
    console.log(
      `${i + 1}.`,
      count1 % 2 === 0
        ? count1 / 2 + count2 / 2
        : 2 + (count1 - 1) / 2 + (count2 - 1) / 2
    );
  }
  stack = [];
  i++;
}
