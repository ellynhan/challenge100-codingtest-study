/*

프로그래머스 / 내적 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/70128

< 소요 시간 >
3분

<프로그래밍 계획>
  - 각 인덱스 값끼리 곱한 새로운 배열 생성
*/

function solution(a, b) {
  return a.reduce((answer, number, index) => answer + number * b[index], 0);
}
