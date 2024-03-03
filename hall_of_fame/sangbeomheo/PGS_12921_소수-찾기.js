/*

프로그래머스 / 소수 찾기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12921

< 소요 시간 >
8분

*/

function solution(n) {
  let count = 0;
  for (let i = 2; i <= n; i++) {
    isPrime(i) && count++;
  }

  return count;
}

function isPrime(number) {
  if (number === 2) return true;

  for (let i = 2; i <= Math.floor(Math.sqrt(number)); i++) {
    if (number % i === 0) return false;
  }

  return true;
}
