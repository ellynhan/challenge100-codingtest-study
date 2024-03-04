/*

    Programmers / 위장 / Level 2 / 00:09:32
    https://school.programmers.co.kr/learn/courses/30/lessons/42578


    ## Pseudo Code ##
    
    1. target과 nums[i]의 차인 diff를 구한다.
    2. hash에서 diff가 있는지 찾는다.
    3. ㄴ 있으면 찾은 값의 인덱스와 i를 리턴한다.
    4. ㄴ 없으면 hash에 {nums[i]: i} 추가한다.

*/

function solution(clothes) {
  const clothesMap = {};

  for (const [_, kind] of clothes) {
    clothesMap[kind] ? clothesMap[kind]++ : (clothesMap[kind] = 1);
  }

  return Object.values(clothesMap).reduce((a, c) => a * (c + 1), 1) - 1;
}
