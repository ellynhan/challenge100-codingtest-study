/*

프로그래머스 / 키패드 누르기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/67256

< 소요 시간 >
90분

<프로그래밍 계획>
numbers 요소 순회
- 왼,오 손가락의 위치 정보를 저장
- 1,4,7 이면 => L
- 3,6,9 이면 => R
- 2,5,8,0 이면
  - 왼,오별로 거리 측정하기. 눌러야하는 키패드와 왼,오 위치 값 비교
  - 거리가 같다면 => hand 리턴
  - 거리가 다르다면 => 거리가 더 가까운 hand 리턴

*/

const keypad = {
  1: [0, 0],
  2: [0, 1],
  3: [0, 2],
  4: [1, 0],
  5: [1, 1],
  6: [1, 2],
  7: [2, 0],
  8: [2, 1],
  9: [2, 2],
  10: [3, 0],
  11: [3, 1],
  12: [3, 2],
};

function getDistance(keyA, keyB) {
  return (
    Math.abs(keypad[keyA][0] - keypad[keyB][0]) +
    Math.abs(keypad[keyA][1] - keypad[keyB][1])
  );
}

function getHandCommand(hand) {
  return hand === "right" ? "R" : "L";
}

function solution(numbers, hand) {
  let leftHand = 10;
  let rightHand = 12;

  return numbers
    .map((value) => {
      const number = value ? value : 11;
      switch (number % 3) {
        case 0:
          rightHand = number;
          return "R";
        case 1:
          leftHand = number;
          return "L";
        case 2:
          const distanceR = getDistance(number, rightHand);
          const distanceL = getDistance(number, leftHand);

          if (distanceR === distanceL) {
            hand === "right" ? (rightHand = number) : (leftHand = number);
            return getHandCommand(hand);
          }

          if (distanceR > distanceL) {
            leftHand = number;
            return "L";
          }

          if (distanceR < distanceL) {
            rightHand = number;
            return "R";
          }
      }
    })
    .join("");
}
