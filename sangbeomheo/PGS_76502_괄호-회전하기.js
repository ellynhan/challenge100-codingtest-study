/*

프로그래머스 / 괄호 회전하기 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/76502

< 소요 시간 >
1시간 30분

<프로그래밍 계획>
    1. s의 길이만큼 순회
        - x만큼 s의 앞에서 잘라서 뒤에 붙여서 회전된 문자열 생성
        - 회전된 문자열이 올바른 괄호 문자열인지 체크해서 카운트

    2. 올바른 괄호 문자열인지 체크
        - 체크를 위한 스택 배열 생성
        - 문자열을 문자하나씩 체크
          - [, {, ( 일 경우
            => 스택에 푸시

          - ), }, ] 일 경우
            => 스택의 마지막 괄호와 쌍을 이루면 => 스택의 마지막 요소 제거
            => 스택의 마지막 괄호와 쌍을 이루지 못하면 => 올바른 괄호 x
*/

function solution(s) {
  let count = 0;

  for (let x = 0; x < s.length; x++) {
    let state = true;
    const stack = [];
    const replaced = [...s.substring(x), ...s.substring(0, x)];

    for (const bracket of replaced) {
      if (isOpen(bracket)) {
        stack.push(bracket);
        continue;
      }

      if (isMatched(stack[stack.length - 1], bracket)) {
        stack.pop();
        continue;
      }

      state = false;
      break;
    }
    if (state === true && stack.length === 0) count++;
  }

  return count;
}

function isOpen(bracket) {
  if (bracket === "{" || bracket === "(" || bracket === "[") return true;
  return false;
}

function isMatched(front, back) {
  if (
    (front === "{" && back === "}") ||
    (front === "(" && back === ")") ||
    (front === "[" && back === "]")
  )
    return true;
  return false;
}
