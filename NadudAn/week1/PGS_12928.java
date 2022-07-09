public class Solution {
    public static int solution(int n) {
        int answer = 0;

        if(n <= 1) return answer = n;

        answer = 1 + n;

        for(int i = 2; i <= Math.sqrt(n); i++) {
            if(n % i == 0) {
                answer += i;
                if(n / i != i) answer += (n / i);
            }
        }

        return answer;
    }

}
