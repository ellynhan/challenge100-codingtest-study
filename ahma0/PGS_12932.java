import java.util.ArrayList;

public class Solution {

    public static int[] solution(long n) {
        ArrayList<Long> answer = new ArrayList<>();

        while(true) {
            if(n <= 0) break;

            answer.add(n % 10);
            n /= 10;
        }

        return answer.stream()
                .mapToInt(Long::intValue)
                .toArray();
    }

}