import java.util.*;

class Solution {
    boolean solution(String s) {
        int flag = 0;

        for (Character c : s.toCharArray()) {
            if (c == '(') flag++;
            else {
                if (flag <= 0) {
                    return false;
                }

                flag--;
            }
        }

        return flag == 0;
    }
}