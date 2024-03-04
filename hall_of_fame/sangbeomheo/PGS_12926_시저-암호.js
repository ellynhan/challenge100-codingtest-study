/*

프로그래머스 / 시저 암호 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12926

< 소요 시간 >
1시간 40분

<프로그래밍 계획>
  - 아스키코드 65~90 => 대문자, 97~120 => 소문자
  - 밀기전 코드가 대문자인지 소문지인지에서 분기
    - 대문자면 밀어도 대문자
    - 소문자면 밀어도 소문자
  - 밀어서 변환한 문자들을 전부 join해서 리턴
*/

function solution(s, n) {
  return s
    .split("")
    .map((char) => {
      if (char === " ") return " ";

      const [code, pushedCode] = [char.charCodeAt(), char.charCodeAt() + n];
      const [upperMin, upperMax, lowerMax, totalAlphabet] = [65, 90, 122, 26];

      if (code >= upperMin && code <= upperMax) {
        return String.fromCharCode(
          pushedCode > upperMax ? pushedCode - totalAlphabet : pushedCode
        );
      }
      return String.fromCharCode(
        pushedCode > lowerMax ? pushedCode - totalAlphabet : pushedCode
      );
    })
    .join("");
}
