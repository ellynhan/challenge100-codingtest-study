package BOJ.제로10773;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

  static int K;

  static long sum = 0;

  static List<Long> list = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    input(br);
    solve();
    print();

    br.close();
  }

  private static void input(BufferedReader br) throws IOException {
    K = Integer.parseInt(br.readLine());
    for (int i = 0; i < K; i++) {
      int input = Integer.parseInt(br.readLine());
      if (input == 0) {
        list.remove(list.size() - 1);
      } else {
        list.add((long) input);
      }
    }
  }

  private static void solve() {
    for (Long l : list) {
      sum += l;
    }
  }

  private static void print() {
    System.out.println(sum);
  }
}
