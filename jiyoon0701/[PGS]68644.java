import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        ArrayList<Integer>  ab = new ArrayList<>();
        for(int i =0; i<numbers.length; i++){
            for(int j = i+1; j<numbers.length; j++){
                if(!ab.contains(numbers[i] + numbers[j])){
                    ab.add(numbers[i] + numbers[j]);
                }
            }
        }
        Collections.sort(ab);
        answer = ab.stream().mapToInt(i->i).toArray();
        return answer;
    }
}
