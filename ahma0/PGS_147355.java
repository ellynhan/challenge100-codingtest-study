public class Solution {

    public static int solution(String t, String p) {
        int answer = 0;
        long N = Long.parseLong(p);

        for(int i = 0; i <= t.length() - p.length(); i++) {

            if(Long.parseLong(t.substring(i, i + p.length())) <= N)
                answer++;
        }

        return answer;
    }

}