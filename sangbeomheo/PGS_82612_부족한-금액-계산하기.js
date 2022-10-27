/*

프로그래머스 / 부족한 금액 계산하기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/82612

< 소요 시간 >
19분

<프로그래밍 계획>
  - count번 타게 됐을 때 총 금액 : (금액 * count) + ...
  - 예산 money가 더 크면 0 리턴 / 예산이 부족하면 부족한 금액 리턴

*/

function solution(price, money, count) {
  let totalPrice = 0;

  while (count > 0) {
    totalPrice += price * count;
    count--;
  }

  return money > totalPrice ? 0 : (money - totalPrice) * -1;
}
