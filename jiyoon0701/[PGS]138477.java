import java.lang.Math;
import java.util.Arrays;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        int first = score[0];
        int[] count = new int[k];
        count[0] = first;
        answer[0] = first;
        for(int i=1; i<score.length; i++){
            if(i < k) {
                if(first < score[i]){
                    answer[i] = first;
                }
                else {
                    first = score[i];
                    answer[i] = first;
                }
                count[i] = score[i]; 
            }
            
            else{
                Arrays.sort(count);  
                if(count[0] < score[i]){
                    count[0] = score[i];
                    Arrays.sort(count);  
                    answer[i] = count[0];
                }
                else {
                    answer[i] = count[0];
                }
            }
        }
        
        return answer;
    }
}
