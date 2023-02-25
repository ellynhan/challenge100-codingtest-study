package 수정렬하기3_10989;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  static int N;

  static int[] integers;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    input(br);
    solve();
    print(bw);

    //bw.flush();
    //br.close();
    //bw.close();
  }

  private static void input(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    integers = new int[N];
    for (int i = 0; i < N; i++) {
      integers[i] = Integer.parseInt(br.readLine());
    }
  }

  private static void solve() {
    Arrays.sort(integers);
  }

  private static void print(BufferedWriter bw) {
    StringBuilder stringBuilder = new StringBuilder();
    for (int i = 0; i < N; i++) {
      stringBuilder.append(integers[i]).append("\n");
    }
    System.out.println(stringBuilder);
  }
}

