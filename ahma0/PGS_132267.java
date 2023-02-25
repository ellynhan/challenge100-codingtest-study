
public class Solution {

    public static int solution(int a, int b, int n) {
        int answer = 0, temp;

        while (true) {
            temp = n / a * b;
            n = temp + n % a;
            answer += temp;

            if(n < a) break;
        }

        return answer;
    }

}