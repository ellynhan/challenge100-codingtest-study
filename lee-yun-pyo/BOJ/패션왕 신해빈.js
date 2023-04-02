const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];

const testCase = input.slice(1);
let j = 0;
for (let i = 0; i < N; i++) {
  let obj = {};
  for (let k = j; k < +testCase[j] + j; k++) {
    const clothes = testCase[k + 1].trim().split(" ");
    const kind = clothes[1];
    const name = clothes[0];
    if (Object.keys(obj).includes(kind)) {
      obj[kind].push(name);
    } else {
      obj[kind] = [];
      obj[kind].push(name);
    }
  }
  console.log(solution(obj));
  j += +testCase[j] + 1;
}

function solution(obj) {
  const values = Object.values(obj).map((v) => v.length);
  const result = values
    .map((i) => i + 1)
    .reduce((accumulator, currentValue) => accumulator * currentValue, 1);
  return result - 1;
}

/*
  --solution 인자 값
  1: { headgear: ["hat", "turban"], eyewear: ["sunglasses"] },
  2: { face: ["mask", "sunglasses", "makeup"] },
*/
