
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static int[] solution(String today, String[] terms, String[] privacies) {
        ArrayList<Integer> answer = new ArrayList();
        String[] s;
        Map<String, Integer> map = new HashMap<>();

        for(int i = 0; i < terms.length; i++) {
            s = terms[i].split(" ");
            map.put(s[0], Integer.parseInt(s[1]) * 28);
        }

        int now = toDate(today), date;

        for(int i = 0; i < privacies.length; i++) {
            s = privacies[i].split(" ");
            date = toDate(s[0]) + map.get(s[1]);

            if(now >= date) answer.add(i + 1);
        }

        return answer.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }

    public static int toDate(String s) {
        return Integer.parseInt(s.split("\\.")[2])
                + Integer.parseInt(s.split("\\.")[1]) * 28
                + (Integer.parseInt(s.split("\\.")[0]) - 2000) * 12 * 28;
    }

}