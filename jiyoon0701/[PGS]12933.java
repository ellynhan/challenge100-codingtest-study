import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        String a = String.valueOf(n);
        String an = "";
        String[] b = a.split("");
        Arrays.sort(b,Collections.reverseOrder());
        for(String h : b){
            an = an.concat(h);
        }
        answer =Long.parseLong(an);
        return answer;
    }
}
