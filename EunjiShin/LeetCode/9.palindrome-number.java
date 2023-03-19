package Easy;

/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (isNegative(x) || isEndWithZero(x)) {
            return false;
        }

        if (isSingleDigit(x)) {
            return true;
        }

        int reverse = makeReverse(x);
        return x == reverse;
    }

    private static boolean isNegative(int x) {
        return x < 0;
    }

    private static boolean isEndWithZero(int x) {
        return x != 0 && x % 10 == 0;
    }

    private static boolean isSingleDigit(int x) {
        return x > 0 && x < 10;
    }

    private static int makeReverse(int x) {
        int reverse = 0;
        while (x != 0) {
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        return reverse;
    }

}
// @lc code=end
