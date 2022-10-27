/*

프로그래머스 / 로또의 최고 순위와 최저 순위 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/77484

< 소요 시간 >
24분

*/

function solution(lottos, win_nums) {
  const zeroCount = lottos.filter((num) => num === 0).length;
  const minCount = lottos.filter((num) => win_nums.includes(num)).length;
  const maxCount = zeroCount + minCount;

  const maxRank = getRank(maxCount);
  const minRank = getRank(minCount);
  return [maxRank, minRank];
}

function getRank(count) {
  let rank;
  switch (count) {
    case 6:
      rank = 1;
      break;
    case 5:
      rank = 2;
      break;
    case 4:
      rank = 3;
      break;
    case 3:
      rank = 4;
      break;
    case 2:
      rank = 5;
      break;
    default:
      rank = 6;
  }
  return rank;
}
