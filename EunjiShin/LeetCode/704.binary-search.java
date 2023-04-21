package Easy;

/*
 * @lc app=leetcode id=704 lang=java
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int pivot = 0;

        while (left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] == target)
                return pivot;
            if (nums[pivot] > target)
                right--;
            if (nums[pivot] <= target)
                left++;
        }

        return -1;
    }
}
// @lc code=end
