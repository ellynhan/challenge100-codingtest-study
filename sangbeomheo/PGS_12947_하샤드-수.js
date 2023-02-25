/*

프로그래머스 / 하샤드 수 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12947

< 소요 시간 >
3분

*/

function solution(x) {
  const sum = `${x}`.split("").reduce((a, c) => Number(a) + Number(c));

  return x % sum === 0 ? true : false;
}
