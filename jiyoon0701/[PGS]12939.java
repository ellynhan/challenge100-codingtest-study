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
        
        Collections.sort(b);

        answer = b.get(0) + " " + b.get(b.size()-1);
        
        return answer;
    }
}