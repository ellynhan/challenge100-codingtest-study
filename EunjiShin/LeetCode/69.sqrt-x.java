package Easy;

/*
 * @lc app=leetcode id=69 lang=java
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
    // public int mySqrt(int x) {
    // if (x < 2) {
    // return x;
    // }

    // long result = 1;
    // while (result * result <= x) {
    // ++result;
    // }
    // return (int) result - 1;
    // }

    public int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int start = 1;
        int end = x / 2;
        while (start <= end) {
            int mid = (start + end) / 2;
            if ((long) mid * mid <= x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
}
// @lc code=end
