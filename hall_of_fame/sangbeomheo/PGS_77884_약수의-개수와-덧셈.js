/*

프로그래머스 / 약수의 개수와 덧셈 / 레벨 1
https://programmers.co.kr/learn/courses/30/lessons/77884

< 소요 시간 >
15분

< 프로그래밍 계획 >

1. left부터 ~ right까지 1씩 올라가면서 순회
2. 약수를 구해서 배열에 저장
3. 배열의 길이가 짝수면 +, 홀수면 -

*/

function solution(left, right) {
  let answer = 0;

  for (let i = left; i <= right; i++) {
    const divisors = [];
    for (let j = 1; j <= i / 2; j++) {
      if (i % j === 0) divisors.push(j);
    }
    divisors.push(i);

    divisors.length % 2 === 0 ? (answer += i) : (answer -= i);
  }

  return answer;
}
