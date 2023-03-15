package Easy;

/*
 * @lc app=leetcode id=13 lang=java
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {

    public int romanToInt(String s) {
        int result = 0;
        int n = s.length();
        int[] romanArray = makeRomanArray(s, n);

        for (int i = 0; i < n - 1; i++) {
            if (romanArray[i] < romanArray[i + 1])
                result -= romanArray[i];
            else
                result += romanArray[i];
        }
        return result + romanArray[n - 1];
    }

    private static int[] makeRomanArray(String s, int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 'I':
                    array[i] = 1;
                    break;
                case 'V':
                    array[i] = 5;
                    break;
                case 'X':
                    array[i] = 10;
                    break;
                case 'L':
                    array[i] = 50;
                    break;
                case 'C':
                    array[i] = 100;
                    break;
                case 'D':
                    array[i] = 500;
                    break;
                case 'M':
                    array[i] = 1000;
                    break;
            }
        }
        return array;
    }

}
// @lc code=end
