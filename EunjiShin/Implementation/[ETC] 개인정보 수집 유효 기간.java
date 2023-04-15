package other;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    public static final int FIRST_YEAR = 2000;
    public static final int FIRST_MONTH = 1;
    public static final int FIRST_DAY = 1;
    public static final int MAX_DATE = 28;

    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<>();

        Map<String, Integer> termMap = makeTermMap(terms);
        int todayInt = makeDateToInt(today);
        for (int i = 0; i < privacies.length; i++) {
            String privacy = privacies[i];
            String[] array = privacy.split(" ");
            int check = termMap.get(array[1]) * 28;
            int day = makeDateToInt(array[0]);
            if (day + check <= todayInt) {
                answer.add(i + 1);
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }

    public static Map<String, Integer> makeTermMap(String[] terms) {
        Map<String, Integer> termMap = new HashMap<>();
        for (String str : terms) {
            String[] array = str.split(" ");
            termMap.put(array[0], Integer.parseInt(array[1]));
        }
        return termMap;
    }

    public static int makeDateToInt(String date) {
        String[] array = date.split("\\.");
        int year = (Integer.parseInt(array[0]) - FIRST_YEAR) * 12 * MAX_DATE;
        int month = (Integer.parseInt(array[1]) - FIRST_MONTH) * MAX_DATE;
        int day = Integer.parseInt(array[2]) - FIRST_DAY;
        return year + month + day;
    }

}
