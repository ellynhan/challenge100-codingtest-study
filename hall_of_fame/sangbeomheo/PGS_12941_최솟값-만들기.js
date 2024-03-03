/*

프로그래머스 / 최솟값 만들기 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/12941

< 소요 시간 >
5분

<프로그래밍 계획>
순서대로 제일 작은 수와 제일 큰 수를 곱해야 한다.
  - A, B를 각각 오름차순, 내림차순 정렬
  - 각 배열의 같은 인덱스 값을 곱해서 더하기

*/

function solution(A, B) {
  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);

  return A.reduce((sum, number, index) => sum + number * B[index], 0);
}
