/*

프로그래머스 / 문자열 다루기 기본 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12918

< 소요 시간 >
20분

<프로그래밍 계획>
  - 문자열 e가 들어가면 지수로 인식해서 Number()를 하면 숫자로 변한다!!!!
*/

function solution(s) {
  if (s.length !== 4 && s.length !== 6) return false;
  if (isNaN(s)) return false;
  if (s.includes("e")) return false; // e!!!!!!!!!
  return true;
}
