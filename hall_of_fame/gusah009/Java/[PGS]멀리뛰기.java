class Solution {

  private static final int MOD_NUM = 1234567;
  private static final int[] dp = new int[2001];

  public long solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD_NUM;
    }

    return dp[n];
  }
}