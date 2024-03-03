/*

프로그래머스 / 같은 숫자는 싫어 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12906

< 소요 시간 >
5분

<프로그래밍 계획>
  - filter로 바로 뒷 요소와 같지 않는 요소만 남김

*/

function solution(arr) {
  return arr.filter((number, index) => number !== arr[index + 1]);
}
