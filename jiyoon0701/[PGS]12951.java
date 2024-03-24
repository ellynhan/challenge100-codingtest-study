import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] a = s.split("");
        boolean flag = true;
        
        for(String b : a) {
            answer += flag ? b.toUpperCase() : b.toLowerCase();
            flag = b.equals(" ")? true : false;
        }
        
        return answer;
    }
}