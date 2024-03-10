import java.util.*;
class Solution {
    public int[] solution(int n, long left, long right) {
        int[]answer=new int[(int)right-(int)left+1];
        int a=0;
        for(long i=left;i<=right;i++){
            int b=(int)(i/(long)n);
            int c=(int)(i%(long)n);
            if(c-b<=0){
                answer[a++]=b+1;
            }else{
                answer[a++]=c+1;
            }
        }
        return answer;
    }
}
