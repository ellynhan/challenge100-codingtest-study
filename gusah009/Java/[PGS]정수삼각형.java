class Solution {

  private static final int size = 500;

  int[][] dp = new int[size][size];

  public int solution(int[][] triangle) {
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.length - 1; i++) {
      int[] row = triangle[i + 1];
      for (int j = 0; j < i + 1; j++) {
        dp[i + 1][j] = Math.max(dp[i + 1][j], row[j] + dp[i][j]);
        dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], row[j + 1] + dp[i][j]);
      }
    }
    int answer = 0;
    for (int i = 0; i < triangle.length; i++) {
      answer = Math.max(answer, dp[triangle.length - 1][i]);
    }
    return answer;
  }
}