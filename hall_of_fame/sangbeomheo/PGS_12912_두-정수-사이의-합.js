/*

프로그래머스 / 두 정수 사이의 합 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12912

< 소요 시간 >
10분

<프로그래밍 계획>
  1. a, b 의 크기를 비교해 min, max 정하기
  2. min ~ max 의 정수 개수 리턴

*/

function solution(a, b) {
  if (a === b) return a;

  const [min, max] = [Math.min(a, b), Math.max(a, b)];

  let answer = 0;

  for (let i = min; i <= max; i++) answer += i;

  return answer;
}
