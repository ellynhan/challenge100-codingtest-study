import java.util.*;
class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        long left=(long)r1*r1;
        long right=(long)r2*r2;
        long sum=0;
        for(long i=-1*r2;i<=0;i++){
            long l=left-(i*i);
            long r=right-(i*i);
            if(l<0){
                l=0;
            }
            sum+=(long)Math.floor(Math.sqrt(r))-(long)Math.ceil(Math.sqrt(l))+1;
        }
        answer=(sum-(r2-r1+1))*4;
        return answer;
    }
}
