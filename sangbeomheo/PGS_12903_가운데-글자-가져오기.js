/*

프로그래머스 / 가운데 글자 가져오기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12903

< 소요 시간 >
7분

*/

function solution(s) {
  if (s.length % 2 === 0) {
    return s[parseInt(s.length / 2) - 1] + s[parseInt(s.length / 2)];
  }
  return s[parseInt(s.length / 2)];
}
