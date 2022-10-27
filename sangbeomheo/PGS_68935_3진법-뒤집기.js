/*

프로그래머스 / 3진법 뒤집기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/68935

< 소요 시간 >
20분

<프로그래밍 계획>
  - n => 3진법 => 리버스 => 10진법

  - 몰랐던 것
    parseInt(n, m) => m진수인 숫자n을 10진수화
*/

function solution(n) {
  return parseInt(n.toString(3).split("").reverse().join(""), 3);
}
