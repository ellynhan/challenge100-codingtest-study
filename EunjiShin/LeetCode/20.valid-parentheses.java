package Easy;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {

    private static final Map<Character, Character> bracketMap = new HashMap<Character, Character>() {
        {
            put('(', ')');
            put('{', '}');
            put('[', ']');
        }
    };

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else if (stack.isEmpty()) {
                return false;
            } else {
                if (bracketMap.get(stack.pop()) != ch) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

}
// @lc code=end
