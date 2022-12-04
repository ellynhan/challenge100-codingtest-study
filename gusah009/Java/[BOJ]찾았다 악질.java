import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// 20m
public class Main {

  static int N, M;
  static List<Integer> lalpa;
  static List<List<Integer>> others = new ArrayList<>();
  static boolean answer = false;

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
    String[] s = br.readLine().split(" ");
    N = Integer.parseInt(s[0]);
    M = Integer.parseInt(s[1]);

    lalpa = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt)
        .collect(Collectors.toList());

    for (int i = 0; i < N - 1; i++) {
      others.add(Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt)
          .collect(Collectors.toList()));
    }
  }

  private static void solve() {
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
      int sum = 0;
      for (int j = 0; j < M; j++) {
        sum += Math.abs(others.get(i).get(j) - lalpa.get(j));
      }
      if (sum > 2000) {
        count++;
      }
    }
    if (count >= (N % 2 == 0 ? (N - 1) / 2 + 1 : (N - 1) / 2)) {
      answer = true;
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(answer ? "YES" : "NO");
  }
}
