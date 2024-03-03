/*

프로그래머스 / 과일 장수 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/135808

< 소요 시간 >
21분

<프로그래밍 계획>
    1. 박스의 개수 구하기.
      - 박스의 개수가 0이면 0 return
  
    2. 사용할 사과 배열 구하기
      - 사과들을 내림차순 정렬
      - 남는 사과들은 배열에서 제거
  
    3. 박스에서 제일 낮은 등급 * 사과 개수 = 박스의 가격
      - 박스의 수 만큼 반복문을 돌면서 해당 박스의 제일 낮은 가격으로 박스 가격 계산 후 더하기


*/

function solution(k, m, score) {
  const boxes = Math.floor(score.length / m);

  if (boxes <= 0) return 0;

  const length = boxes * m;
  const apples = score.sort((a, b) => b - a).slice(0, length);

  let profit = 0;

  for (let i = 0; i < length; i += m) {
    profit += apples[i + m - 1] * m;
  }

  return profit;
}
