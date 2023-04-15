package Easy;

/*
 * @lc app=leetcode id=70 lang=java
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    public int climbStairs(int n) {

        int[] result = new int[n + 1];
        result[0] = 1;
        result[1] = 1;

        for (int i = 2; i <= n; i++) {
            result[i] += result[i - 1] + result[i - 2];
        }

        return result[n];
    }
}
// @lc code=end
