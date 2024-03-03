//  LeetCode / Contains Duplicate / Easy / 00:06:48
//  https://leetcode.com/problems/contains-duplicate/

var containsDuplicate = function (nums) {
  // 맵 생성
  const map = {};

  // 반복문실행
  // => 맵에서 value를 키로 검색해서 기존 값이 있으면(true) 즉시 true 리턴 or 없으면(undifined) true 할당
  for (const value of nums) {
    if (map[value]) return true;
    map[value] = true;
  }

  // 중복된 값이 없으면 false 리턴
  return false;
};

var containsDuplicate1 = function (nums) {
  // nums Set에 넣어서 중복 제거
  // nums 길이와 set 길이 비교
  // => 길이가 다르면 false, 같으면 true 리턴
  return nums.length !== new Set(nums).size;
};
