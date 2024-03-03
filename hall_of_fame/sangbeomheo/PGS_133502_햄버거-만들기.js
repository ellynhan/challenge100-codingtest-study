/*

프로그래머스 / 햄버거 만들기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/133502

< 소요 시간 >
11분

*/

function solution(ingredient) {
  const stack = [];
  let count = 0;

  ingredient.forEach(value => {
    stack.push(value);

    if (stack.slice(-4).join('') === '1231') {
      stack.splice(-4);
      count++;
    }
  });

  return count;
}
