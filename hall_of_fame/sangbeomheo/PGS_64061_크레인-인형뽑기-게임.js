/*

프로그래머스 / 크레인 인형뽑기 게임 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/64061

< 소요 시간 >
18분

<프로그래밍 계획>
- 스택 활용

  1. moves를 활용해서 인형의 위치 값 배열을 만듬
  2. 바구니 스택 만듬
  3. 위치 값을 순회한다
    - 위치 값에 따라 바구니에 인형을 넣고 뺌

*/

function solution(board, moves) {
  const positions = moves.map((v) => v - 1);
  const basket = [];
  let count = 0;

  positions.forEach((position) => {
    board.some((row) => {
      if (!row[position]) return false;

      if (row[position] === basket[basket.length - 1]) {
        basket.pop();
        count += 2;
      } else {
        basket.push(row[position]);
      }
      row[position] = 0;
      return true;
    });
  });

  return count;
}
