/*

프로그래머스 / 수박수박수박수박수박수? / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12922

< 소요 시간 >
7분

<프로그래밍 계획>
  n길이 크기의 배열 생성 => 배열 인덱스가 짝수면 '수', 홀수면 '짝
*/

function solution(n) {
  return Array.from({ length: n }, (_, i) => {
    return i % 2 === 0 ? "수" : "박";
  }).join("");
}
