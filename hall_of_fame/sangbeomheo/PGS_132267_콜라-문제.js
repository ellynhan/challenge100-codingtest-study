/*

프로그래머스 / 콜라 문제 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/132267

< 소요 시간 >
6분

*/

function solution(returnUnit, receivedUnit, initialBottleCount) {
  let restBottleCount = initialBottleCount;
  let totalReceivedCount = 0;

  while (restBottleCount >= returnUnit) {
    const share = parseInt(restBottleCount / returnUnit);
    const returnCount = share * returnUnit;
    const receivedCount = share * receivedUnit;

    restBottleCount = (restBottleCount % returnUnit) + receivedCount;
    totalReceivedCount += receivedCount;
  }

  return totalReceivedCount;
}
