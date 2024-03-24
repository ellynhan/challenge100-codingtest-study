import java.lang.*;
import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] a = s.split(" ");
        ArrayList b = new ArrayList<Integer>();
        
        for(String c : a){
            b.add(Integer.parseInt(c));
        }
        
        int maxNum = (int)Collections.max(b);
        int minNum = (int)Collections.min(b);
        
        answer = minNum + " " + maxNum;
        
        return answer;
    }
}
