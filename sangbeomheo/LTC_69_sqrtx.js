/*

    LeetCode / Sqrt(x) / Easy / 00:20:33
    https://leetcode.com/problems/sqrtx/


    ## Pseudo Code ##
    
    ㄴ 이진탐색으로 중간 값이 제곱근이 되는지 비교한다.
    ㄴ 제곱근이거나 가장 가까운 낮은 정수를 리턴해야함

    0. 예외 처리 : x가 0 또는 1일 경우 x를 리턴

    1. 변수 설정
        ㄴ low : 1 (최소값 - 2, 3 일 경우 1이 정답)
        ㄴ high : x - 1 (최대값 - x가 x의 제곱근이 될 수 없음)
        ㄴ candidate : low와 high의 중간 정수 값

    2. while 반복문
        ㄴ low 가 high와 같거나 작을 때만 반복문 실행

        ㄴ 1. candidate * candidate가 x와 같으면 candidate 리턴
        ㄴ 2.
          ㄴ candidate * candidate가 x보다 크면 => high를 candidate - 1로 변경 (앞쪽에서 찾자)
          ㄴ candidate * candidate가 x보다 작으면 => low를 candidate + 1로 변경 (뒷쪽에서 찾자)
          ㄴ 새로운 candidate 구하기 

    3. 반복문이 다 돌고 종료됬으면 candidate 리턴

*/

var mySqrt = function (x) {
  if (x === 0 || x === 1) return x;

  let low = 1;
  let high = x - 1;
  let candidate = Math.floor((low + high) / 2);

  while (low <= high) {
    const square = candidate * candidate;

    if (square === x) return candidate;

    if (square > x) {
      high = candidate - 1;
    } else {
      low = candidate + 1;
    }

    candidate = Math.floor((low + high) / 2);
  }

  return candidate;
};
