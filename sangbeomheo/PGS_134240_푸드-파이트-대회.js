/*

프로그래머스 / 푸드 파이트 대회 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/134240

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
