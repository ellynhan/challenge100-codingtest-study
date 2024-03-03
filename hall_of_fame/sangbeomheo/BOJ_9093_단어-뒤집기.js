/*

백준 / 단어 뒤집기 / 브론즈 1
https://www.acmicpc.net/problem/9093

< 소요 시간 >
12분

< 프로그래밍 계획 >

  1. 문장를 단어로 쪼개서 배열화
  2. 개별 단어들을 map으로 뒤집기
  3. 다시 문장으로 합치기

*/

const [n, ...arr] = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const answer = [];

arr.forEach((line) => {
  const [...word] = line.split(" ");

  const converted = word
    .map((string) =>
      string.length === 1 ? string : string.split("").reverse().join("")
    )
    .join(" ");

  answer.push(converted);
});

console.log(answer.join("\n"));
