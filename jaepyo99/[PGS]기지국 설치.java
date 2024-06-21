import java.util.*;
class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer=0;
        Queue<Integer>queue=new LinkedList<>();
        int idx=0;
        int now=1;
        int l=stations.length;
        while(now<=n){
            if(idx<l&&stations[idx]-w<=now){
                now=stations[idx]+w+1;
                idx++;
            }else{
                answer+=1;
                now+=(2*w)+1;
            }
        }
        return answer;
    }
}
