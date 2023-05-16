import java.util.*;
class Solution {
    public int solution(int[] number) {
        int answer = 0;
        int count = 0;
        for(int i = 0; i<number.length; i++){
            count = number[i];
            for(int j = i+1; j<number.length; j++){
                count += number[j];
                for(int k = j+1; k<number.length; k++){
                    count += number[k];
                    if (count == 0){
                        answer+=1;
                    }
                    count -= number[k];
                }
                count -= number[j];
            }
        }
        return answer;
    }
}
