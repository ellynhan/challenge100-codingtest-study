import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
    	HashMap<String, List<String>> map = new HashMap<>();
    	for(String[] lst : clothes) {
    		if(!map.keySet().contains(lst[1])) 
    			map.put(lst[1], new ArrayList<>());
    		map.get(lst[1]).add(lst[0]);
        }
    	
        int answer = 1;
        for(String key : map.keySet()) {
            answer *= (map.get(key).size() + 1);
        }

        return answer-1;
    }
}
