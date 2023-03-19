package Easy;

/*
 * @lc app=leetcode id=58 lang=java
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
    public int lengthOfLastWord(String s) {
        int result = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                if (result != 0) {
                    return result;
                }
            } else {
                result += 1;
            }
        }

        return result;
    }
}
// @lc code=end
