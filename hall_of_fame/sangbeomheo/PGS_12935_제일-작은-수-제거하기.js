/*

프로그래머스 / 제일 작은 수 제거하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12935

< 소요 시간 >
2분

*/

function solution(arr) {
  const min = Math.min(...arr);
  const minIndex = arr.indexOf(min);

  arr.splice(minIndex, 1);

  return arr.length ? arr : [-1];
}
