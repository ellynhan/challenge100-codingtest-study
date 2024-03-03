/*

프로그래머스 / 이진 변환 반복하기 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/70129

< 소요 시간 >
15분

*/

function solution(s) {
  let convertion = 0;
  let allZeros = 0;

  while (s !== '1') {
    const deleteZeros = s.replaceAll('0', '');
    allZeros += s.length - deleteZeros.length;

    s = deleteZeros.length.toString(2);
    convertion++;
  }

  return [convertion, allZeros];
}
