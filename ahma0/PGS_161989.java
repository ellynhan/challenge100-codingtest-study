
public class Solution {

    public int solution(int n, int m, int[] section) {
        int answer = 0, max = 0;

        for(int i = 0; i < section.length; i++) {
            if(section[i] < max)
                continue;

            answer += 1;
            max = section[i] + m;
        }

        return answer;
    }

}