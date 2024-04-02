import java.util.*;
class Solution {
    private int answer=600001;
    public long sum(int[]arr){
        long sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
        }
        return sum;
    }
    
    public int solution(int[] queue1, int[] queue2) {
        long sum1=sum(queue1);
        long sum2=sum(queue2);
        
        Queue<Integer>q1=new LinkedList<>();
        Queue<Integer>q2=new LinkedList<>();
        
        for(int i=0;i<queue1.length;i++){
            q1.offer(queue1[i]);
            q2.offer(queue2[i]);
        }
        int answer=0;
        int val;
        while(sum1!=sum2){
            if(answer>(queue1.length+queue2.length)*2){
                return -1;
            }
            if(sum1<sum2){
                val=q2.poll();
                q1.offer(val);
                sum1+=(long)val;
                sum2-=(long)val;
            }else{
                val=q1.poll();
                q2.offer(val);
                sum2+=(long)val;
                sum1-=(long)val;
            }
            answer++;
        }
        return answer;
    }
}
