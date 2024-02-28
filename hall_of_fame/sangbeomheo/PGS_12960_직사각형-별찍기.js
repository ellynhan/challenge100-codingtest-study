/*

프로그래머스 / 직사각형 별찍기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12969

< 소요 시간 >
3분

*/

process.stdin.setEncoding("utf8");
process.stdin.on("data", (data) => {
  const n = data.split(" ");
  const a = Number(n[0]);
  const b = Number(n[1]);

  for (let i = 0; i < b; i++) {
    console.log("*".repeat(a));
  }
});
