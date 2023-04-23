package Easy;

import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=409 lang=java
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
    public int longestPalindrome(String s) {
        Set<Character> set = new HashSet<>();
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!set.add(ch)) {
                set.remove(ch);
                count++;
            }
        }

        return (set.isEmpty()) ? 2 * count : 2 * count + 1;
    }
}
// @lc code=end
