// https://school.programmers.co.kr/learn/courses/30/lessons/42747
import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        
        for (int h = citations.length; h >= 1; h--) {
            int index = citations.length - h;
            if (citations[index] >= h) {
                return h;
            }
        }
        return 0;
    }
}
