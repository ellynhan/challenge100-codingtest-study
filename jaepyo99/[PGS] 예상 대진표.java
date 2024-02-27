import java.util.*;
class Solution{
    public int solution(int n, int a, int b)
    {
        Queue<Integer>queue=new LinkedList<>();
        for(int i=1;i<=n;i++){
            if(a==i || b==i){
                queue.add(1);
            }else{
                queue.add(0);
            }
        }
        
        int first;
        int second;
        int cnt=1;
        int num=0;
        while(true){
            if(num==n){
                num=0;
                n=n/2;
                cnt+=1;
            }
            first=queue.remove();
            second=queue.remove();
            if(first==1 && second==1){
                return cnt;
            }else{
                if(first>second){
                    queue.add(first);
                }else{
                    queue.add(second);
                }
                num+=2;
            }
        }
    }
}
