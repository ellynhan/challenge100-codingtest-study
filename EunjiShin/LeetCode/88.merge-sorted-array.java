package Easy;

/*
 * @lc app=leetcode id=88 lang=java
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int lastIndex = m - 1;
        int lastIndex2 = n - 1;
        int totalIndex = m + n - 1;

        while (lastIndex2 >= 0) {
            if (lastIndex >= 0) {
                if (nums1[lastIndex] > nums2[lastIndex2]) {
                    nums1[totalIndex--] = nums1[lastIndex--];
                } else {
                    nums1[totalIndex--] = nums2[lastIndex2--];
                }
            } else {
                nums1[totalIndex--] = nums2[lastIndex2--];
            }
        }

    }
}
// @lc code=end
