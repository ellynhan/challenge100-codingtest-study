// https://school.programmers.co.kr/learn/courses/30/lessons/12917
import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(String s) {
        return Arrays.stream(s.split(""))
            .sorted((s1, s2) -> s2.compareTo(s1))
            .collect(Collectors.joining());
    }
}
