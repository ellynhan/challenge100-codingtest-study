/*

프로그래머스 / 음양 더하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/76501

< 소요 시간 >
3분

<프로그래밍 계획>
- absolutes 요소를 하나씩 계산한다.
- 계산할 때는 signs의 같은 인덱스의 값으로 계산. true면 +, false면 -

*/

function solution(absolutes, signs) {
  return absolutes.reduce((sum, absolute, index) => {
    return signs[index] ? (sum += absolute) : (sum -= absolute);
  }, 0);
}
