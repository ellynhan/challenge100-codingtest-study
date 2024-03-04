// https://school.programmers.co.kr/learn/courses/30/lessons/42748
import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int index = 0; index < answer.length; index++) {
            int i = commands[index][0] - 1;
            int j = commands[index][1];
            int k = commands[index][2] - 1;
            int[] sub = Arrays.copyOfRange(array, i , j);
            Arrays.sort(sub);
            answer[index] = sub[k];
        }
        
        return answer;
    }
}
