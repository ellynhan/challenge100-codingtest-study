import static java.lang.Math.max;

import java.util.Arrays;

class Solution {

  private static final int[][] dp = new int[100000][4];

  int solution(int[][] land) {
      
    for (int i = 0; i < 4; i++) {
      dp[0][i] = land[0][i];
    }
    for (int i = 1; i < land.length; i++) {
      for (int j = 0; j < 4; j++) {
        dp[i][j] = max(dp[i - 1][(j + 1) % 4],
            max(dp[i - 1][(j + 2) % 4], dp[i - 1][(j + 3) % 4])) + land[i][j];
      }
    }
    return Arrays.stream(dp[land.length - 1]).max().getAsInt();
  }
}