import java.util.*;
class Solution {
    public int solution(int x, int y, int n) {
        Queue<Integer>queue=new LinkedList<>();
        int answer = 0;
        int[]arr=new int[y+1];
        Arrays.fill(arr,-1);
        arr[y]=0;
        queue.offer(y);
        while(!queue.isEmpty()){
            int key=queue.poll();
            int a=-1;
            int b=-1;
            int c=-1;
            if(key-n>=0){
                a=key-n;
            }
            if(key/2>=0 && key%2==0){
                b=key/2;
            }
            if(key/3>=0 && key%3==0){
                c=key/3;
            }
            if(a!=-1&&(arr[a]==-1 || arr[a]>arr[key]+1)&&a>=x){
                arr[a]=arr[key]+1;
                queue.offer(a);
            }if(b!=-1&&(arr[b]==-1 || arr[b]>arr[key]+1)&&b>=x){
                arr[b]=arr[key]+1;
                queue.offer(b);
            }if(c!=-1&&(arr[c]==-1 || arr[c]>arr[key]+1)&&c>=x){
                arr[c]=arr[key]+1;
                queue.offer(c);
            }
            if(a<=x&&b<=x&&c<=x){
                break;
            }
            
        }
        return arr[x];
    }
}
