package Easy;

import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> numMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (numMap.containsKey(target - nums[i])) {
                result[0] = numMap.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            numMap.put(nums[i], i);
        }

        return result;
    }
}
// @lc code=end
