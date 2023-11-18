package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RGB {

  static int N = 0;
  static int R = 0;
  static int G = 1;
  static int B = 2;
  static int[][] cost;
  static int[][] dp;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    cost = new int[N][3];
    dp = new int[N][3];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine(), " ");
      cost[i][R] = Integer.parseInt(st.nextToken());
      cost[i][G] = Integer.parseInt(st.nextToken());
      cost[i][B] = Integer.parseInt(st.nextToken());
    }

    initDP();
    paint();

    System.out.println(Math.min(Math.min(cost[N-1][R], cost[N-1][G]), cost[N-1][B]));
  }

  public static void initDP() {
    dp[0][R] = cost[0][R];
    dp[0][G] = cost[0][G];
    dp[0][B] = cost[0][B];
  }

  public static void paint() {
    for (int i = 1; i < N; i++) {
      cost[i][R] += Math.min(cost[i-1][G], cost[i-1][B]);
      cost[i][G] += Math.min(cost[i-1][R], cost[i-1][B]);
      cost[i][B] += Math.min(cost[i-1][R], cost[i-1][G]);
    }
  }

}
