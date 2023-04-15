import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static int solution(int cacheSize, String[] cities) {
        int answer = 0;

        Queue<String> queue = new LinkedList<>();

        for(int i = 0; i < cities.length; i++) {
            if(queue.contains(cities[i].toLowerCase())) {
                queue.remove(cities[i].toLowerCase());
                queue.add(cities[i].toLowerCase());
                answer += 1;
            }
            else {
                queue.add(cities[i].toLowerCase());
                answer += 5;
                if(queue.size() > cacheSize) queue.remove();
            }
        }

        return answer;
    }

}