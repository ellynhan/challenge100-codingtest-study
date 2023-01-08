import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  static int N, answer, q_divideByFive, r_divideByFive;

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
    q_divideByFive = N / 5;
    r_divideByFive = N % 5;
  }

  private static void solve() {
    if (r_divideByFive == 0) { // 5 로 나누어 떨어지면 바로 정답.
      answer = q_divideByFive;
      return;
    }

    while (true) {
      if ((N - q_divideByFive * 5) % 2 == 0) {
        answer = q_divideByFive + ((N - q_divideByFive * 5) / 2);
        break;
      }
      if (q_divideByFive == 0) {
        answer = -1;
        break;
      }
      q_divideByFive--;
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }
}
