import java.io.BufferedReader;
import java.util.ArrayList;

public class Solution {

    public int[] solution(String[] keymap, String[] targets) {
        ArrayList<Integer> answer = new ArrayList();
        int sum = 0, t;

        for(int i = 0; i < targets.length; i++) {
            for(int j = 0; j < targets[i].length(); j++) {
                t = findTarget(targets[i].charAt(j), keymap);

                if(t == Integer.MAX_VALUE) {
                    answer.add(-1);
                    sum = 0;
                    break;
                }

                sum += t;
            }
            if(sum != 0) answer.add(sum);
            sum = 0;
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }

    public int findTarget(char c, String[] arr) {
        int min = Integer.MAX_VALUE, t = -1;

        for(int i = 0; i < arr.length; i++) {
            t = arr[i].indexOf(c);

            if(t != -1)
                min = Math.min(arr[i].indexOf(c) + 1, min);
        }

        return min;
    }

}