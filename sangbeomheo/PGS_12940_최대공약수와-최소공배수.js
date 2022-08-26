/*

프로그래머스 / 최대공약수와 최소공배수 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12940

< 소요 시간 >
2시간

<프로그래밍 계획>

  // 유클리드 호제 활용
  // 최대공약수 : const gcd = (a, b) => (a % b === 0 ? b : gcd(b, a % b));
  // 최소공배수 : const lcm = (a, b) => (a * b) / gcd(a, b);

*/

function solution(n, m) {
  const [min, max] = [Math.min(n, m), Math.max(n, m)];
  const gcd = getGCD(max, min);
  const lcm = getLCM(max, min, gcd);

  return [gcd, lcm];
}

function getGCD(a, b) {
  return a % b === 0 ? b : getGCD(b, a % b);
}

function getLCM(a, b, gcd) {
  return (a * b) / gcd;
}
