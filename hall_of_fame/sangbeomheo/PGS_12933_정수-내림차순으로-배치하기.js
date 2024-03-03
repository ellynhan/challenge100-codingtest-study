/*

프로그래머스 / 정수 내림차순으로 배치하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12933

< 소요 시간 >
1분

*/

function solution(n) {
  return Number(
    ("" + n)
      .split("")
      .sort((a, b) => b - a)
      .join("")
  );
}
