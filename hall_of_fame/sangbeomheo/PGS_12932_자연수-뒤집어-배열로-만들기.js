/*

프로그래머스 / 자연수 뒤집어 배열로 만들기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12932

< 소요 시간 >
1분

*/

function solution(n) {
  return ("" + n)
    .split("")
    .reverse()
    .map((s) => Number(s));
}
