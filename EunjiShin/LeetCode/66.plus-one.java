package Easy;

/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {

    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] = digits[i] + 1;
                return digits;
            }
            digits[i] = 0;
        }

        // 여기 왔다는건 9999처럼 for문 끝날 때까지 return하지 못 한 경우
        return makeResult(digits);
    }

    public static int[] makeResult(int[] digits) {
        int[] result = new int[digits.length + 1];
        result[0] = 1;
        return result;
    }

}
// @lc code=end
