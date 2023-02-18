/*

프로그래머스 / 폰켓몬 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/1845

< 소요 시간 >
12분

<프로그래밍 계획>
  - Set으로 중복제거 활용
*/

function solution(nums) {
  const limitCount = nums.length / 2;
  const monCount = [...new Set(nums)].length;

  return limitCount < monCount ? limitCount : monCount;
}
