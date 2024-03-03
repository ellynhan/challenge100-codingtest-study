/*

프로그래머스 / x만큼 간격이 있는 n개의 숫자 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12954

< 소요 시간 >
1분

*/

function solution(x, n) {
  return Array.from({ length: n }, (v, i) => x * (i + 1));
}
