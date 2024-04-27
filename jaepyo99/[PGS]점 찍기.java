import java.util.*;
class Solution {
    public long solution(int k, int d) {
        long answer = 0;
        long limit=(long)d*d;
        for(int i=0;i<=d;i+=k){
            long ii=(long)i*i;
            long point=limit-ii;
            int top=(int)Math.sqrt(point);
            answer+= (top/k)+1;
        }
        return answer;
    }
}
