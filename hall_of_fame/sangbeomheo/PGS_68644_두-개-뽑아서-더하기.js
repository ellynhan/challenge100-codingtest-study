/*

프로그래머스 / 두 개 뽑아서 더하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/68644

< 소요 시간 >
11분

*/

function solution(numbers) {
  const result = [];

  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      const number = numbers[i] + numbers[j];
      if (result.find((element) => element === number) === undefined) {
        result.push(number);
      }
    }
  }
  result.sort((a, b) => a - b);

  return result;
}
