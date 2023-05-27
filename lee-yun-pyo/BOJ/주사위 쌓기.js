const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [[N], ...array] = require("fs")
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((i) => i.split(" ").map(Number));

const indexes = [5, 3, 4, 1, 2, 0]; // 마주보는 면의 인덱스

let result = [];
let sum = 0;
for (let i = 0; i < 6; i++) {
  const top = array[0][i]; // 1번 주사위 윗면
  const bottom = array[0][indexes[i]]; // 1번 주사위 아랫면
  let firstArray = array[0].filter((v) => v !== top);
  firstArray = firstArray.filter((v) => v !== bottom);
  sum += Math.max(...firstArray);
  let nextBottom = top;

  // 2번 주사위 이상의 최댓값 구하기
  for (let j = 1; j < N; j++) {
    const bottomIndex = array[j].indexOf(nextBottom);
    const bottom2 = array[j][bottomIndex];
    const top2 = array[j][indexes[bottomIndex]];
    let array2 = array[j].filter((v) => v !== top2);
    array2 = array2.filter((v) => v !== bottom2);
    sum += Math.max(...array2);
    nextBottom = top2;
  }

  result.push(sum);
  sum = 0;
}

console.log(Math.max(...result));
