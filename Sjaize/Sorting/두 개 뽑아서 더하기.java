// https://school.programmers.co.kr/learn/courses/30/lessons/68644
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> set = new HashSet<> ();
        
        for (int i = 0; i < numbers.length - 1; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                set.add(numbers[i] + numbers[j]);
            }
        }
        
        return set.stream().mapToInt(Integer::intValue).sorted().toArray();
    }
}
