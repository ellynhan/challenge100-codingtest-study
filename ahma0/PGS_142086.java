import java.util.*;

public class Solution {

    public int[] solution(String s) {
        LinkedHashMap<Character, Integer> map = new LinkedHashMap();
        ArrayList<Integer> arrayList = new ArrayList();

        for(int i = 0; i < s.length(); i++) {
            if(!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), i);
                arrayList.add(-1);
                continue;
            }
            arrayList.add(i - map.get(s.charAt(i)));
            map.put(s.charAt(i), i);
        }

        return arrayList.stream().mapToInt(Integer::intValue).toArray();
    }

}