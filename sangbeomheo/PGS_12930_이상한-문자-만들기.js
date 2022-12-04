/*

프로그래머스 / 이상한 문자 만들기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12930

< 소요 시간 >
12분

*/

function solution(s) {
  const words = s.split(" ");

  const convertedWords = words.map((word) =>
    word
      .split("")
      .map((alphabet, index) => {
        if (index % 2 === 0) return alphabet.toUpperCase();
        return alphabet.toLowerCase();
      })
      .join("")
  );

  const answer = convertedWords.join(" ");
  return answer;
}
