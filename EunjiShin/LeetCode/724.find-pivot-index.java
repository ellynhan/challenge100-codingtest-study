package Easy;

import java.util.Arrays;

/*
 * @lc app=leetcode id=724 lang=java
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
    public int pivotIndex(int[] nums) {
        int totalSum = Arrays.stream(nums).sum();
        int leftSum = 0;

        for (int i = 0; i < nums.length; i++) {
            int rightSum = totalSum - nums[i] - leftSum;
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }

        return -1;
    }
}
// @lc code=end
