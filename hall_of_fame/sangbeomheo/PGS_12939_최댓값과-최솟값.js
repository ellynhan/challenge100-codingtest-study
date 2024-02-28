/*

프로그래머스 / 최댓값과 최솟값 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/12939

< 소요 시간 >
2분

*/

function solution(s) {
  const number = s
    .split(' ')
    .map(str => str * 1)
    .sort((a, b) => a - b);

  return `${number[0]} ${number[number.length - 1]}`;
}
