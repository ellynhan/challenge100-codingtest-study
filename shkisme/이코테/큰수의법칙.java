import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  static int N, M, K, answer = 0;

  static int[] numbers;

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
    K = Integer.parseInt(st.nextToken());
    numbers = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; ++i) {
      numbers[i] = Integer.parseInt(st.nextToken());
    }
  }

  private static void solve() {
    numbers = Arrays.stream(numbers).sorted().toArray();
    int max = numbers[numbers.length - 1];
    int nextMax = numbers[numbers.length - 2]; // 간단하게 가장 큰수, 그리고 그 다음으로 큰 수를 구할 수 있다. (문제에서 두 수가 같아도 상관없다 했으니 괜찮음)

    for (int i = 0; i < M; ++i) {
      if ((i + 1) % (K + 1) == 0) {
        answer += nextMax;
      } else {
        answer += max;
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }

}
