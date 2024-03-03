/*

프로그래머스 / 자릿수 더하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12931

< 소요 시간 >
2분

*/

function solution(n) {
  return n
    .toString()
    .split("")
    .reduce((a, c) => Number(a) + Number(c), 0);
}
