/*

프로그래머스 / 삼총사 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/131705

< 소요 시간 >
38분

*/

function solution(number) {
  return getCombinations(number, 3).filter(v => v.reduce((a, c) => a + c) === 0)
    .length;
}

function getCombinations(arr, n) {
  if (n === 1) return arr.map(v => [v]);

  let result = [];

  arr.forEach((fixed, idx, arr) => {
    const rest = arr.slice(idx + 1);
    const perms = getCombinations(rest, n - 1);
    const combine = perms.map(v => [fixed, ...v]);
    result.push(...combine);
  });

  return result;
}
