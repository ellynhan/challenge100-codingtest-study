/*

프로그래머스 / 나머지가 1이 되는 수 찾기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/87389

< 소요 시간 >
2분

*/

function solution(n) {
  for (let i = 1; i <= n; i++) {
    if (n % i === 1) return i;
  }
}
