/*

프로그래머스 / 약수의 합 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12928

< 소요 시간 >
2분

<프로그래밍 계획>
  - 나머지가 0인 수들을 더하기
*/

function solution(num) {
  let sum = 0;
  for (let i = 1; i <= num; i++) {
    if (num % i === 0) sum += i;
  }
  return sum;
}
