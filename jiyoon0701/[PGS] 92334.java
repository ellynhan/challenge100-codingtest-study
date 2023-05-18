import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        List<Integer> result = new ArrayList<Integer>();
        
        for(int a : ingredient){
            result.add(a);

            if(result.size() >= 4){
                if(result.get(result.size() - 4) == 1 &&
                   result.get(result.size() - 3) == 2 &&
                   result.get(result.size() - 2) == 3 &&
                   result.get(result.size() - 1) == 1 
                  ) {
                    answer++;
                    for(int i= 0; i < 4; i++){
                        result.remove(result.size() - 1);
                    }
                }
            }
        }
    
        return answer;
    }
}
