import java.util.*;
class Solution {
    public int[] solution(int n, int s) {
        int[]answer=new int[n];
        int index;
        int common=s/n; //기본값
        int left=s%n;
        if(common<=0){
            return new int[]{-1};
        }
        Arrays.fill(answer,common);
        int tmp=n-1;
        index=tmp;
        for(int i=0;i<left;i++){
            if(index<0){
                index=tmp;
            }
            answer[index%n]+=1;
            index--;
        }
        return answer;
    }
}
