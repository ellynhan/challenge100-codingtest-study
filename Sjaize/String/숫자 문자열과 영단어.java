// https://school.programmers.co.kr/learn/courses/30/lessons/81301
class Solution {
    private static final String[] words = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    public int solution(String s) {
        for (int i = 0; i < words.length; i++) {
            s = s.replace(words[i], Integer.toString(i));
        }
        return Integer.parseInt(s);
    }
}
