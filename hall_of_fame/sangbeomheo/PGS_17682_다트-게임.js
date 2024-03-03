/*

프로그래머스 / 다트 게임 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/17682

< 소요 시간 >
52분

<프로그래밍 계획>
  1. 기회별로 점수를 넣은 배열을 선언. scores
  2. scores에 점수를 넣기 전에 임시 점수를 저장할 변수를 선언. tempScore
  3. 문자열 dartResult를 순회 (char of dartResult)
      - char가 숫자로 형변환 가능하면 => tempScore에 더하기
      - char가 숫자로 형변환이 불가능하다면 => 기본점수 완성, char는 SDT*# 중에 하나임
          - 기본점수가 완성됐으니 scores에 push
          - char가 "D"라면 => 현재점수를 2제곱
          - char가 "T"라면 => 현재점수를 3제곱
          - char가 "#"라면 => 현재점수를 음수로 변경
          - char가 "*"라면 => 현재점수를 2배, 이전점수가 있다면 이전점수도 2배
  4. scores를 전부 합해서 리턴

*/
function solution(dartResult) {
  const scores = [];

  let tempScore = "";

  for (const char of dartResult) {
    // char가 숫자로 형변환 가능하면 => tempScore에 더하기
    if (!isNaN(1 * char)) {
      tempScore += char;
      continue;
    }

    // char가 숫자로 형변환이 불가능하다면 => 기본점수 완성, char는 SDT*# 중에 하나임

    // 기본점수가 완성됐으니 scores에 push
    if (tempScore) {
      scores.push(tempScore);
      tempScore = "";
    }

    const currScoreIndex = scores.length - 1;
    const prevScoreIndex = scores.length - 2;

    // char가 "D"라면 => 현재점수를 2제곱
    // char가 "T"라면 => 현재점수를 3제곱
    // char가 "#"라면 => 현재점수를 음수로 변경
    // char가 "*"라면 => 현재점수를 2배, 이전점수가 있다면 이전점수도 2배
    if (char === "D") scores[currScoreIndex] = scores[currScoreIndex] ** 2;
    if (char === "T") scores[currScoreIndex] = scores[currScoreIndex] ** 3;
    if (char === "#") scores[currScoreIndex] *= -1;
    if (char === "*") {
      scores[currScoreIndex] *= 2;
      if (prevScoreIndex >= 0) scores[prevScoreIndex] *= 2;
    }
  }

  return scores.reduce((sum, score) => sum + Number(score), 0);
}
