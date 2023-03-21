import java.lang.*;
class Solution {
    public long solution(long n) {
        long answer = -1;
        String a = String.valueOf(Math.sqrt(n));
        int s = a.indexOf(".");
        int num = a.length();
        if(a.charAt(s+1) =='0' && s+2 == num){
            answer = (long) Math.pow((Math.sqrt(n) + 1),2);
        }
        return answer;
    }
}
