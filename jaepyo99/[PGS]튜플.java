import java.util.*;

class Solution {
    public String[] remove(String s){
        String r = s.substring(1, s.length()-1);
        return r.split(",");
    }
    public void print(String[] sen){
        for(String s:sen){
            System.out.println(s);
        }
    }
    public int[] solution(String s) {
        StringBuilder sb = new StringBuilder(s);
        Map<String, Integer> map = new HashMap<>();
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='{' ||s.charAt(i)=='}'){
                sb.setCharAt(i, ' ');
                continue;
            }
        }
        String sw =sb.toString();
        
        String[]q=sw.replaceAll(" ",  "").split(",");
        for(String w:q){
            map.put(w, map.getOrDefault(w, 0) + 1);
        }
        List<String> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys,(v1,v2)->map.get(v2).compareTo(map.get(v1)));
        int[] answer = new int[keys.size()];
        for (int i = 0; i < keys.size(); i++) {
            answer[i]=Integer.valueOf(keys.get(i));
        }

        return answer;
    }
}
