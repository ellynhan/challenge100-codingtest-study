/*

프로그래머스 / 핸드폰 번호 가리기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12948

< 소요 시간 >
6분

*/

function solution(phone_number) {
  const length = phone_number.length;
  const last4 = phone_number.slice(length - 4);
  return "*".repeat(length - 4) + last4;
}
