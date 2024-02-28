/*

프로그래머스 / 문자열 내 마음대로 정렬하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12915

< 소요 시간 >
34분

<프로그래밍 계획>
  1. n인덱스 문자가 다르다면 => n 인덱스 숫자를 비교
  2. n인덱스 문자가 같다면 => 문자열 자체를 비교
*/

function solution(strings, n) {
  return strings.sort((a, b) => {
    if (a[n] > b[n]) return 1;
    if (a[n] < b[n]) return -1;
    if (a[n] === b[n]) return a > b ? 1 : -1;
    return 0;
  });
}
