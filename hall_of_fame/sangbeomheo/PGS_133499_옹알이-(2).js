/*

프로그래머스 / 옹알이 (2) / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/133499

< 소요 시간 >
8분

*/

function solution(babblings) {
  return babblings.reduce((count, babbling) => {
    if (is연속발음보유(babbling)) return count;
    return is가능발음(babbling) ? count + 1 : count;
  }, 0);
}

function is연속발음보유(babbling) {
  const 연속발음s = ['ayaaya', 'yeye', 'woowoo', 'mama'];
  return 연속발음s.some(연속발음 => babbling.includes(연속발음));
}

function is가능발음(babbling) {
  const 발음s = ['aya', 'ye', 'woo', 'ma'];

  for (const 발음 of 발음s) {
    babbling = babbling.split(발음).join('0');
    if (!isNaN(babbling)) return true;
  }

  return false;
}
