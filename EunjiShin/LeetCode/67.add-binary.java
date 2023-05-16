package Easy;

import java.util.Arrays;

/*
 * @lc app=leetcode id=67 lang=java
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {

    public String addBinary(String a, String b) {
        int size = Math.max(a.length(), b.length());
        String newA = makeStr(a, size);
        String newB = makeStr(b, size);

        boolean flag = false;
        StringBuilder sb = new StringBuilder();

        for (int i = size - 1; i >= 0; i--) {
            int aNum = newA.charAt(i) - '0';
            int bNum = newB.charAt(i) - '0';
            int sum = aNum + bNum + (flag ? 1 : 0);
            flag = sum > 1;
            sb.append(sum % 2);
        }

        if (flag) {
            sb.append('1');
        }

        return sb.reverse().toString();
    }

    public static String makeStr(String str, int size) {
        if (str.length() >= size) {
            return str;
        }
        char[] chars = new char[size - str.length()];
        Arrays.fill(chars, '0');
        return new String(chars) + str;
    }

}
// @lc code=end
