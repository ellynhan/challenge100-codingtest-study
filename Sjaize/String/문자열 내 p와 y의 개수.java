// https://school.programmers.co.kr/learn/courses/30/lessons/12916
class Solution {
    boolean solution(String s) {
        String str1 = s.replaceAll("[pP]", "");
        String str2 = s.replaceAll("[Yy]", "");
        return str1.length() == str2.length();
    }
}
