
import java.util.*;

public class Solution {

    public String[] solution(String[] players, String[] callings) {
        HashMap<String, Integer> map = new HashMap<>();
        HashMap<Integer, String> map2 = new HashMap<>();
        String temp = "";

        for(int i = 0; i < players.length; i++) {
            map.put(players[i], i);
            map2.put(i, players[i]);
        }

        for(int i = 0; i < callings.length; i++) {
            map.put(callings[i], map.get(callings[i]) - 1);
            temp = map2.get(map.get(callings[i]));
            map.put(temp, map.get(temp) + 1);

            map2.put(map.get(callings[i]), callings[i]);
            map2.put(map.get(temp), temp);
        }

        return map2.values().toArray(new String[0]);
    }

}