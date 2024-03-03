/*

프로그래머스 / 평균 구하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12944

< 소요 시간 >
1분

*/

function solution(arr) {
  return arr.reduce((a, c) => a + c) / arr.length;
}
