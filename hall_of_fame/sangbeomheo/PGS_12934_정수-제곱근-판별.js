/*

프로그래머스 / 정수 제곱근 판별 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12934

< 소요 시간 >
12분

<프로그래밍 계획>
  - Number.isInteger() : 정수판별!!!

*/

function solution(n) {
  const sqrtNumber = Math.sqrt(n);
  return Number.isInteger(sqrtNumber) ? Math.pow(sqrtNumber + 1, 2) : -1;
}
