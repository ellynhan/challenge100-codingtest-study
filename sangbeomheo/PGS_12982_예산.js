/*

프로그래머스 / 예산 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12982

< 소요 시간 >
7분

<프로그래밍 계획>
  1. d를 오름차순 정렬함
  2. d를 앞에서부터 합하면서 budget과 비교
*/

function solution(d, budget) {
  d.sort((a, b) => a - b);

  let count = 0;

  for (let i = 0; i < d.length; i++) {
    if (d[i] > budget) return count;
    budget -= d[i];
    count++;
  }
  return count;
}
