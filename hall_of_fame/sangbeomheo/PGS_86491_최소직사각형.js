/*

프로그래머스 / 최소직사각형 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/42889

< 소요 시간 >
11분

<프로그래밍 계획>
    1. 모든 명함을 가로, 세로 길이 중에 더 긴 쪽으로? 놓는다.
    2. 그랬을 때 더 긴 쪽 중 제일 큰 길이, 더 짧은 쪽 중 제일 짧은 길이가 지갑의 크기가 된다.
    3. 두 길이를 곱해서 리턴.

*/
function solution(sizes) {
  let [max, min] = [0, 0];

  sizes.forEach((size) => {
    if (size[0] > size[1]) {
      size[0] > max && (max = size[0]);
      size[1] > min && (min = size[1]);
    } else {
      size[1] > max && (max = size[1]);
      size[0] > min && (min = size[0]);
    }
  });

  return max * min;
}
