import java.util.*;
class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        int result = 0;
        Arrays.sort(d);
        for(int i=0;i<d.length;i++){
            result+=d[i];
            if(result > budget){
                answer=i;
                break;
            }
        }
        if(result <= budget){
            answer = d.length;
        }
        return answer;
    }
}
