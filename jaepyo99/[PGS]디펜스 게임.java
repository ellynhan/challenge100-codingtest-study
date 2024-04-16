import java.util.*;
class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> queue=new PriorityQueue<>(Collections.reverseOrder());
        int i=0;
        int round=enemy.length;
        for(i=0;i<round;i++){
            n-=enemy[i];
            queue.offer(enemy[i]);
            if(n<0){
                if(k>0){
                    k--;                    
                    n+=queue.poll();
                }else{
                    return i;
                }
            }             
        }
        return round;
    }
}
