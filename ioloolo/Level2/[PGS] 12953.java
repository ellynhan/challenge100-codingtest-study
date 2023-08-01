import java.math.*;

class Solution {
    public int solution(int[] arr) {
        int answer = arr[0];

        for (int i = 1; i < arr.length; ++i) {
            answer = lcm(answer, arr[i]);
        }

        return answer;
    }

    private int lcm(int a, int b) {
        return a*b / BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
    }
}