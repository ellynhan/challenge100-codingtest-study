import static java.lang.Integer.MAX_VALUE;
import static java.lang.Integer.MIN_VALUE;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  static int N, M, answer;

  static int[][] cards;

  static int[] minCards;

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
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    cards = new int[N][M];

    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) {
        cards[i][j] = Integer.parseInt(st.nextToken());
      }
    }
  }

  private static void solve() {
    minCards = new int[N];
    for (int i = 0; i < N; ++i) {
      minCards[i] = Arrays.stream(cards[i]).min().orElse(MIN_VALUE);
    }
    answer = Arrays.stream(minCards).max().orElse(MAX_VALUE);
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }


}
