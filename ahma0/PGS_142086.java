import java.util.*;

public class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        LinkedHashMap<Character, Integer> map = new LinkedHashMap();

        for(int i = 0; i < s.length(); i++) {
            if(!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), i);
                answer[i] = -1;
                continue;
            }
            answer[i] = i - map.get(s.charAt(i));
            map.put(s.charAt(i), i);
        }

        return answer;
    }

}