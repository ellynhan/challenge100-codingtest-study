package DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MostLongSequence {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] array = new int[n+1];
    int[] dp = new int[n+1];

    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    for (int i = 0; i < n; i++) {
      array[i] = Integer.parseInt(st.nextToken());
      // 모든 수열의 크기는 최소 1이니까 dp도 전부 초기화시켜주기
      dp[i] = 1;
    }

    int max = dp[0];

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (array[i] > array[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
      if (max < dp[i]) max = dp[i];
    }
    System.out.println(max);
  }
}
