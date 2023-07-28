class Solution {
    int[] dp = new int[100001];

    public int solution(int n) {
        return fibo(n) % 1234567;
    }

    public int fibo(int n) {
        if (dp[n] != 0) return dp[n];
        if (n == 1 || n == 2) return 1;

        return dp[n] = (fibo(n-1) % 1234567 + fibo(n-2) % 1234567) % 1234567;
    }
}