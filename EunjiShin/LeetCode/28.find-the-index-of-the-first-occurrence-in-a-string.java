package Easy;

/*
 * @lc app=leetcode id=28 lang=java
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
    // public int strStr(String haystack, String needle) {
    // return haystack.indexOf(needle);
    // }

    public int strStr(String haystack, String needle) {
        if (haystack.equals(needle))
            return 0;

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            if (haystack.substring(i, i + needle.length()).equals(needle)) {
                return i;
            }
        }

        return -1;
    }
}
// @lc code=end
