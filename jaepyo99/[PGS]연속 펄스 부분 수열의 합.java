import java.util.*;
class Solution {
    long MAX=Long.MIN_VALUE;
    public long solution(int[] sequence) {
        int n=sequence.length;
        long[] p1=new long[n];
        long[] p2=new long[n];
        
        int mul=1;
        for(int i=0;i<n;i++){
            p1[i]=sequence[i]*mul;
            mul*=-1;
            p2[i]=sequence[i]*mul;
        }
        
        long[] dp1=new long[n];
        long[] dp2=new long[n];
        
        dp1[0]=p1[0];
        dp2[0]=p2[0];
            
        for(int i=1;i<n;i++){
            dp1[i]=Math.max(dp1[i-1]+p1[i],p1[i]);
            
            dp2[i]=Math.max(dp2[i-1]+p2[i],p2[i]);
        }
        
        for(int i=0;i<n;i++){
            if(dp1[i]>MAX){
                MAX=dp1[i];
            }
            if(dp2[i]>MAX){
                MAX=dp2[i];
            }
        }
        
        return MAX;
    }
}
