package 이코테;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Main {

  static int N, count = 0;

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
  }

  private static void solve() {
    for (int i = 0; i < N + 1; ++i) {
      for (int j = 0; j < 60; ++j) {
        for (int k = 0; k < 60; ++k) {
          if (LocalTime.of(i, j, k)
              .format(DateTimeFormatter.ofPattern("HH:mm:ss"))
              .contains("3")) {
            count++;
          }
        }
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(count));
  }
  
}
