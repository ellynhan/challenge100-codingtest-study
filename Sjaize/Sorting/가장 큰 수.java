// https://school.programmers.co.kr/learn/courses/30/lessons/42746
import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(int[] numbers) {
        return Arrays.stream(numbers)
                        .mapToObj(String::valueOf)
                        .sorted((s1, s2) -> {
                            int original = Integer.parseInt(s1 + s2);
                            int reversed = Integer.parseInt(s2 + s1);
                            return reversed - original;
                        })
                        .collect(Collectors.joining(""))
                        .replaceAll("^0+", "0");
    }
}
