package Easy;

/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {

        int current = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.length; i++) {
            int next = prices[i];
            if (current > next) {
                current = next;
            } else {
                maxProfit = Math.max(maxProfit, next - current);
            }
        }

        return maxProfit;

    }
}
// @lc code=end
