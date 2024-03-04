/*

    LeetCode / Binary Search / Easy / 00:44:17
    https://leetcode.com/problems/binary-search/


    ## Pseudo Code ##
    
    1. 배열의 중간 값과 target을 비교 (이진탐색)
        ㄴ start, mid, end index 값 변수 설정

    2. while 반복문
        ㄴ start 가 mid 같거나 보다 작을 때만 반복문 실행 (같거나는 nums의 길이가 1,2일 때)

        ㄴ 1. mid value가 target과 같으면 => mid 리턴
        ㄴ 2.
          ㄴ mid value값이 target보다 크면 => end를 mid - 1로 변경 (앞쪽에서 찾자)
          ㄴ mid value값이 target보다 작으면 => start를 mid + 1로 변경 (뒷쪽에서 찾자)
          ㄴ 새로운 mid 구하기 
        

*/

var search = function (nums, target) {
  const getMid = (start, end) => Math.floor((start + end) / 2);

  let start = 0;
  let end = nums.length - 1;
  let mid = getMid(start, end);

  while (start <= mid) {
    const value = nums[mid];

    if (value === target) {
      return mid;
    }

    value > target ? (end = mid - 1) : (start = mid + 1);
    mid = getMid(start, end);
  }
  return -1;
};
