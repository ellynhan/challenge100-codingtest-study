import static java.lang.Math.max;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  private static final int MAX_DAY = 15 + 5;
  static int N;
  static int[] T = new int[MAX_DAY];
  static int[] P = new int[MAX_DAY];
  static int[] dp = new int[MAX_DAY + 1];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    input(br);
    solve();
    print(bw);

    bw.flush();
    br.close();
    bw.close();
  }

  private static void input(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    for (int n = 0; n < N; n++) {
      String[] inputStrArr = br.readLine().split(" ");
      T[n] = Integer.parseInt(inputStrArr[0]);
      P[n] = Integer.parseInt(inputStrArr[1]);
    }
  }

  private static void solve() {
    dp[0] = 0;
    for (int n = 0; n < N; n++) {
      dp[n + 1] = max(dp[n + 1], 0);
      for (int n2 = n; n2 >= 0; n2--) {
        if (T[n2] + n2 <= n + 1) {
          dp[n + 1] = max(dp[n + 1], dp[n2] + P[n2]);
        }
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    int answer = 0;
    for (int n = 0; n <= N; n++) {
      answer = max(answer, dp[n]);
    }
    bw.write(String.valueOf(answer));
  }
}
