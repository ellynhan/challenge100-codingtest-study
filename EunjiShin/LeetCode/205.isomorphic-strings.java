package Easy;

import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=205 lang=java
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Character sc = s.charAt(i);
            Character tc = t.charAt(i);

            // 한 글자에는 하나의 글자만 매핑될 수 있음
            if (!map.containsKey(sc) && map.containsValue(tc)) {
                return false;
            }
            if (map.containsKey(sc) && !map.get(sc).equals(tc)) {
                return false;
            }
            map.put(sc, tc);
        }
        return true;
    }
}
// @lc code=end
