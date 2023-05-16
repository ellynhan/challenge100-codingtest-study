package Easy;

/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int mid = 0;
        int end = nums.length - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                end = mid - 1;
            if (nums[mid] < target)
                start = mid + 1;
        }

        return (nums[mid] > target) ? mid : mid + 1;
    }
}
// @lc code=end
