import java.util.HashMap;

class Solution {
    public int[] solution(String s) { // 30
        int[] answer = new int[s.length()];
        HashMap<Character, Integer> maps = new HashMap<>();
        for(int i=0; i<s.length(); i++){
            if (maps.get(s.charAt(i)) == null){
                maps.put(s.charAt(i), i);
                answer[i] = -1;
            }
            else {
                int a = maps.get(s.charAt(i));
                int idx = i-a;
                maps.replace(s.charAt(i), i);
                answer[i] = idx;
            }
        }
        return answer;
    }
}