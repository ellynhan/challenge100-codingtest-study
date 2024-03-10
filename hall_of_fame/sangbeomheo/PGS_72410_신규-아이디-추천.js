/*

프로그래머스 / 신규 아이디 추천 / 레벨 1
https://programmers.co.kr/learn/courses/30/lessons/72410

< 소요 시간 >
60분

*/

// 규칙에 맞지 않는 아이디 입력 -> 유사하고 규칙에 맞는 아이디 추천
// 3 <= IdLength <= 15
// 소문자, 숫자, '-', '_', '.'
// '.' 는 처음과 끝 x, 연속으로 사용 x

// 1 =< new_id =< 1000

function solution(new_id) {
  const step1to3 = new_id
    .toLowerCase() // 1단계: 대문자 -> 소문자 치환
    .replace(/[^\w-.]/gi, "") // 2단계: 소문자, 숫자, '-', '_', '.' 빼고 제외
    .replace(/\.{2,1000}/gi, "."); // 3단계: '.' 연속중복 제거

  // 4단계: 앞 뒤 .제거
  let step4_1 = step1to3;
  if (step1to3[0] === ".") step4_1 = step1to3.slice(1);

  let step4_2 = step4_1;
  if (step4_1[step4_1.length - 1] === ".")
    step4_2 = step4_1.slice(0, step4_1.length - 1);
  console.log("step4_2", step4_2);

  // 5단계: 빈 문자열이면, 'a' 대입
  let step5 = step4_2;
  if (!step4_2.length) step5 = "a";

  // 6단계: 길이가 16이상, 앞에서부터 15까지 자르기, 맨뒤 '.' 자르기
  let step6 = step5;
  if (step5.length > 15) step6 = step5.slice(0, 15);
  if (step6[step6.length - 1] === ".") step6 = step6.slice(0, step6.length - 1);

  // 7단계: 길이가 2이하, 마지막 문자를 길이가 3이 될 때까지 끝에 붙임.

  let step7 = step6;
  while (step7.length < 3) {
    step7 = step7 + step7[step7.length - 1];
  }

  return step7;
}
