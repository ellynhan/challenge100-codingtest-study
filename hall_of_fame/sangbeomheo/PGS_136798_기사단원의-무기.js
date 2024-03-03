/*

프로그래머스 / 기사단원의 무기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/136798

< 소요 시간 >
19분
  
*/

function solution(number, limit, power) {
  const kisas = Array.from({ length: number }, (_, i) => i + 1);
  return kisas
    .map(kisa => {
      const realPower = divisorLength(kisa);
      return realPower > limit ? power : realPower;
    })
    .reduce((a, c) => a + c);
}

const divisorLength = n => {
  let count = 0;

  for (let i = 1; i * i <= n; i++) {
    if (i * i === n) count++;
    else if (n % i === 0) count += 2;
  }

  return count;
};
