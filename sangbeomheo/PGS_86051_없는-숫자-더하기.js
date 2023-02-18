/*

프로그래머스 / 없는 숫자 더하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/86051

< 소요 시간 >
4분

<프로그래밍 계획>
  - 0부터 9의 합은 45.
  - 45에서 배열의 숫자들을 모두 더한 값을 뺀다.
*/

function solution(numbers) {
  return 45 - numbers.reduce((a, c) => a + c);
}
