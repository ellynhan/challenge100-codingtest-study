package Easy;

/*
 * @lc app=leetcode id=392 lang=java
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
    public boolean isSubsequence(String s, String t) {
        int s_index = 0;
        int s_length = s.length();

        if (s_length == 0)
            return true;

        for (int t_index = 0; t_index < t.length(); t_index++) {
            if (s.charAt(s_index) == t.charAt(t_index)) {
                s_index++;
            }
            if (s_index == s_length)
                return true;
        }
        return false;
    }
}
// @lc code=end
