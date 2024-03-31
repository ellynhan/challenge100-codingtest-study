import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {0,0};    

        boolean flag = false; 
        int wordsNum = words.length;
        Set<String> wordSet = new HashSet<>();
        wordSet.add(words[0]);

        for(int i = 1; i<words.length; i++) {
            char end = words[i-1].charAt(words[i-1].length() - 1);
            char start = words[i].charAt(0);
            if(start != end || wordSet.contains(words[i])) {
                flag = true;
                answer[0] = (i+1) % n == 0 ? n : (i+1) % n ;
                answer[1] = (i+1) % n == 0 ? (i+1) / n : (i+1) / n + 1 ;
                break;
            } 
            wordSet.add(words[i]);    
        }
        
        if(flag) return answer;
    
        return answer;
    }
}