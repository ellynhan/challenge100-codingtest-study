/*

프로그래머스 / 행렬의 덧셈 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12950

< 소요 시간 >
10분

*/

function solution(arr1, arr2) {
  return arr1.map((innerArr, index) => {
    return innerArr.map((number, i) => number + arr2[index][i]);
  });
}
