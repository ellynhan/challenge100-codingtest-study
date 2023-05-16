import java.util.*;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {};
        ArrayList<Integer> ar = new ArrayList<>();
        for(int a : arr){
            if(a % divisor == 0){
                ar.add(a);
            }
        }
        if(ar.isEmpty()){
            ar.add(-1);
        }
        
        answer = new int[ar.size()];
        
        for(int i = 0; i<ar.size(); i++){
            answer[i] = ar.get(i);
        }
        Arrays.sort(answer);
        
        return answer;
    }
}
