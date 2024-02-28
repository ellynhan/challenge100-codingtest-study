/*

프로그래머스 / 숫자 문자열과 영단어 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/81301

< 소요 시간 >
19분

*/

// s를 숫자로 변경해보고 NaN이 아니라면 그대로 리턴
//
// char를 하나씩 숫자인지 아닌지 체크
//  - 숫자라면
//      => result에 추가
//  - 숫자가 아니라면
//      => candidate 추가
//      => candidate 영단어 대치표에 있는지 체크
//          - 있으면
//          => 숫자로 바꿔서 result에 추가
//          => candidate 초기화
//
// 모든 char를 체크했다면 result를 숫자형으로 바꿔서 리턴

const numbersMap = {
  zero: "0",
  one: "1",
  two: "2",
  three: "3",
  four: "4",
  five: "5",
  six: "6",
  seven: "7",
  eight: "8",
  nine: "9",
};

function solution(s) {
  if (isNumber(s)) return Number(s);

  let result = "";
  let candidate = "";

  for (char of s) {
    if (isNumber(char)) {
      result += char;
    } else {
      candidate += char;
      if (numbersMap[candidate]) {
        result += numbersMap[candidate];
        candidate = "";
      }
    }
  }
  return Number(result);
}

function isNumber(s) {
  return Number(s) ? true : false;
}

// 다른 사람 풀이
function solution1(s) {
  let numbers = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];
  var answer = s;

  for (let i = 0; i < numbers.length; i++) {
    let arr = answer.split(numbers[i]);
    console.log(numbers[i], arr);
    answer = arr.join(i);
    console.log(answer);
  }

  return Number(answer);
}
