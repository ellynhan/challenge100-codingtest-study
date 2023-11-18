// 1. 알파벳 밀기 연산
// 1-1. 대소문자를 구분하여 각각의 시작점을 기준으로 문자를 밀어서 새로운 알파벳을 만듭니다.
// 1-2.밀기 연산을 수행할 때, 주어진 거리(n)을 이용하여 알파벳을 밀고, z 또는 Z를 넘어가는 경우에는 다시 a 또는 A부터 시작합니다.
// (ASCII :  65('A')부터 시작, 소문자는 97('a')부터 시작)
// String.fromCharCode : 코드값으로 아스키 문자반환
function solution(s, n) {
  return s
    .split("")
    .map((char) => {
      if (char === " ") return " "; // 공백인 경우 그대로 반환
      const code = char.charCodeAt(0); // 현재 문자의 ASCII 코드 값을 가져옴
      console.log(code);
      const start = char === char.toUpperCase() ? 65 : 97;
      return String.fromCharCode(((code - start + n) % 26) + start);
    })
    .join("");
}

console.log(solution("z", 3));
