/*

프로그래머스 / 다음 큰 숫자 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/12911

< 소요 시간 >
10분

<프로그래밍 계획>
- n의 이진수 변환 시 1의 개수 값 구하기
- n+1, +2, +3 ... 하면서 해당 숫자의 이진수 변환시 1의 개수 값 구하기
- 1의 개수 값이 서로 같다면 바로 리턴

*/

function solution(n) {
  const countOfN = [...n.toString(2)].filter((num) => num == 1).length;

  let nextN = n + 1;

  while (true) {
    let countOfNextN = [...nextN.toString(2)].filter((num) => num == 1).length;
    if (countOfN == countOfNextN) break;
    nextN++;
  }

  return nextN;
}
