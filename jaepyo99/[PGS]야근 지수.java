import java.util.*;
class Solution {
    public long solution(int n, int[] works) {
        long answer=0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<works.length;i++){
            pq.offer(works[i]);
        }
        for(int i=0;i<n;i++){
            if(pq.isEmpty()){
                break;
            }
            Integer work=pq.poll();
            if(work-1==0){
                continue;
            }
            pq.offer(work-1);
        }
        while(!pq.isEmpty()){
            answer+=Math.pow(pq.poll(),2);
        }
        return answer;
    }
}
