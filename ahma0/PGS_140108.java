
public class Solution {

    public static int solution(String s) {
        if(s.length() == 1) return 1;

        int answer = 0, cnt1 = 1, cnt2 = 0, index = 0;

        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(index) == s.charAt(i)) cnt1++;
            else cnt2++;

            if(cnt1 == cnt2) {
                answer++;
                index = i + 1;
                cnt1 = 0;
                cnt2 = 0;
            }
            else if(cnt1 != cnt2 && i == s.length() - 1) answer++;

        }

        return answer;
    }

}