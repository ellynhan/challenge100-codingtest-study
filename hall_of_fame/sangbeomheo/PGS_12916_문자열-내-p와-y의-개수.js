/*

프로그래머스 / 문자열 내 p와 y의 개수 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12916

< 소요 시간 >
2분

<프로그래밍 계획>
  - 대문자 or 소문자로 통일 후 p, y의 개수 구해서 비교
*/

function solution(s) {
  let countP,
    countY = 0;

  s.split("")
    .map((c) => c.toUpperCase())
    .forEach((c) => {
      if (c === "P") countP++;
      if (c === "Y") countY++;
    });

  return countP === countY;
}
