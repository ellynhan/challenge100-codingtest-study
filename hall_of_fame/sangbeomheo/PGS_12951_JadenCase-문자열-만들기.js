/*

프로그래머스 / JadenCase 문자열 만들기 / 레벨2
https://school.programmers.co.kr/learn/courses/30/lessons/12951

< 소요 시간 >
36분

<프로그래밍 계획>
1. " "을 기준으로 단어들을 분리해 배열화
2. 단어의 첫글자를 대문자로, 첫글자를 소문자로 변경 후 리턴

- 숫자, 공백은 toUpperCase(), toLowerCase()해도 그대로 유지

*/

function solution(s) {
  return s
    .split(" ")
    .map((word) => {
      const firstValue = word.substring(0, 1).toUpperCase();
      const restValues = word.substring(1).toLowerCase();
      return firstValue + restValues;
    })
    .join(" ");
}
