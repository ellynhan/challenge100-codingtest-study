/*

프로그래머스 / 나누어 떨어지는 숫자 배열 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12910

< 소요 시간 >
4분

<프로그래밍 계획>
  - filter로 나머지 0인 수만 남기고 => 오름차순 정렬 => 리턴(길이가 0이면 -1 리턴)

*/

function solution(arr, divisor) {
  var answer = arr.filter((v) => v % divisor === 0).sort((a, b) => a - b);
  return answer.length < 1 ? [-1] : answer;
}
