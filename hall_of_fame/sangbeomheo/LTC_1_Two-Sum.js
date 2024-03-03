/*

    LeetCode / Two Sum / Easy / 00:24:50
    https://leetcode.com/problems/two-sum/


    ## Pseudo Code ##
    
    1. target과 nums[i]의 차인 diff를 구한다.
    2. hash에서 diff가 있는지 찾는다.
    3. ㄴ 있으면 찾은 값의 인덱스와 i를 리턴한다.
    4. ㄴ 없으면 hash에 {nums[i]: i} 추가한다.

*/

var twoSum = function (nums, target) {
  const hash = {};

  for (let i = 0; i < nums.length; i++) {
    const diff = target - nums[i];

    if (hash[diff] !== undefined) {
      return [hash[diff], i];
    }

    hash[nums[i]] = i;
  }
};
