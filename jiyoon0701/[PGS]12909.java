import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        char[] a = s.toCharArray();
        
        int cntUnpair = 0;
        
        for(char ch : a) {
            cntUnpair += ch == '(' ? 1 : -1;
            if(cntUnpair < 0) return false;
        }
        
        return cntUnpair == 0;
    }
}