package PGS_12925;

public class Solution {
    public static int answer = 0;
    public static String ansStr;

    public int solution(String s) {
        StringBuilder sb = new StringBuilder();

        if (s.charAt(0) == '+') {
            for (int i = 1; i < s.length(); i++) {
                sb.append(s.charAt(i));
            }
            ansStr = sb.toString();
        } else {
            ansStr = s;
        }

        answer = Integer.parseInt(ansStr);
        return answer;
    }
}