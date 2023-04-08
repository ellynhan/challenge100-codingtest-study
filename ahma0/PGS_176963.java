import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Solution {

    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        ArrayList<Integer> arr = new ArrayList();
        int sum = 0;
        LinkedHashMap<String, Integer> map = new LinkedHashMap<>();

        for(int i = 0; i < name.length; i++) {
            map.put(name[i], yearning[i]);
        }

        for(int i = 0; i < photo.length; i++) {
            for(int j = 0; j < photo[i].length; j++) {
                if(map.containsKey(photo[i][j]))
                    sum += map.get(photo[i][j]);
            }
            arr.add(sum);
            sum = 0;
        }

        return arr.stream().mapToInt(Integer::intValue).toArray();
    }

}