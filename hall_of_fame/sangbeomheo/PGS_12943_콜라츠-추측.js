/*

프로그래머스 / 콜라츠 추측 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12943

< 소요 시간 >
10분

*/

function solution(num) {
  if (num === 1) return 0;

  let count = 0;

  while (num != 1) {
    if (count === 500) return -1;
    num % 2 === 0 ? (num = num / 2) : (num = num * 3 + 1);
    count++;
  }

  return count;
}
