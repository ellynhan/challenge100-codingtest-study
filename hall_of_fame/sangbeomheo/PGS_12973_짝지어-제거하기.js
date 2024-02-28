/*

프로그래머스 / 짝지어 제거하기 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/12973

< 소요 시간 >
11분

<프로그래밍 계획>
- s의 길이가 홀수면 0
- 스택 활용
  - s를 순회하면서 char가 스택의 마지막 char와 같으면 같이 제거하고 아니면 추가한다.
  - 순회를 마치고 스택이 비었으면 1, 안비었으면 0

*/

function solution(s) {
  if (s.length % 2 !== 0) return 0;

  const result = [];

  for (const char of s) {
    if (result[result.length - 1] === char) {
      result.pop();
      continue;
    }
    result.push(char);
  }

  return result.length ? 0 : 1;
}
