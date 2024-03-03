// https://school.programmers.co.kr/learn/courses/30/lessons/60057
class Solution {
    public int solution(String s) {
        int result = Integer.MAX_VALUE;
        for (int n = 1; n <= s.length(); n++) {
            StringBuilder sb = new StringBuilder();
            int count = 1;
            int x = 0, y = n;
            String previous = s.substring(x, y);
            while (true) {
                x = x + n;
                y = y + n;
                if (x >= s.length()) {
                    sb.append(count == 1 ? previous : count + previous);
                    break;
                }
                if (y > s.length()) {
                    sb.append(count == 1 ? previous : count + previous);
                    sb.append(s.substring(x, s.length()));
                    break;
                }
                String next = s.substring(x, y);
                if (previous.equals(next)) count++;
                else {
                    sb.append(count == 1 ? previous : count + previous);
                    previous = next;
                    count = 1;
                }
            }
            result = Math.min(result, sb.length());
        }
        return result;
    }
}
