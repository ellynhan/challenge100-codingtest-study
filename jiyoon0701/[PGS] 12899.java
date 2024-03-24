import java.util.*;
class Solution {
    public String solution(int n) {
        String answer = "";
        int[] num = {4, 1, 2};
        ArrayList<Integer> arr = new ArrayList<>();
        
        while(n > 0) {
            int idx = n % 3; 
            n = n / 3;         
            if(idx == 0) {
                n--;
            }
            arr.add(num[idx]);
        }
        Collections.reverse(arr);
        
        for(Integer a : arr) {
            answer+=String.valueOf(a);
        }
        return answer;
    }
}
