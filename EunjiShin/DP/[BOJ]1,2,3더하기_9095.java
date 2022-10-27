package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PlusOneTwoThree {

  static int dp[] = new int[11];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    while (t-- > 0) {
      int n = Integer.parseInt(br.readLine());
      System.out.println(dp[n]);
    }
  }

}
