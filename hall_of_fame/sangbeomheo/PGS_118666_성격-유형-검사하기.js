/*

프로그래머스 / 성격 유형 검사하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/118666

< 소요 시간 >
1시간 2분

<프로그래밍 계획>
  1. survey를 돌면서 사용자의 선택에 따라 캐릭터를 정함
    - survey의 값은 'RT', 'CF'로 두자리 캐릭터
    - 선택이 4보다 크면 뒷자리 캐릭터
    - 선택이 4보다 작으면 앞자리 캐릭터

  2. 점수를 구함
    - 선택이 4보다 크면 4로 나눈 나머지가 점수
    - 선택이 4보다 작으면 4로 나눈 나머지에 -1을 곱하고 4를 더한 숫자가 점수

  3. 점수를 answers에 반영

  4. 최종 캐릭터 구하기
    - 점수가 같으면 알파벳순서가 앞선 것이 유형
    - 4자리를 전부 알파벳순서가 앞선 것으로 기본 세팅
    - 한 자리씩 체크
      - 알파벳순서 뒤의 유형이 더 점수가 높으면 그 유형으로 변경

*/

function solution(survey, choices) {
  const answers = {
    R: 0,
    T: 0,
    C: 0,
    F: 0,
    J: 0,
    M: 0,
    A: 0,
    N: 0,
  };

  survey.forEach((characters, index) => {
    const choice = choices[index];

    if (choice % 4 != 0) {
      const character = choice < 4 ? characters[0] : characters[1];
      const point = choice < 4 ? (choice % 4) * -1 + 4 : choice % 4;
      answers[character] += point;
    }
  });

  const userCharacter = ["R", "C", "J", "A"];
  if (answers["R"] < answers["T"]) userCharacter[0] = "T";
  if (answers["C"] < answers["F"]) userCharacter[1] = "F";
  if (answers["J"] < answers["M"]) userCharacter[2] = "M";
  if (answers["A"] < answers["N"]) userCharacter[3] = "N";

  return userCharacter.join("");
}
