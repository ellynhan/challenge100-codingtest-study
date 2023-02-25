import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  static int[] dices = new int[3];
  static int[] diceNumCount = new int[6];
  static int answer;

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
    dices = Arrays.stream(br.readLine().split(" "))
        .mapToInt(Integer::parseInt)
        .toArray();
    for (int dice : dices) {
      diceNumCount[dice - 1]++;
    }
  }

  private static void solve() {
    for (int i = 0; i < diceNumCount.length; i++) {
      if (diceNumCount[i] == 3) {
        answer = 10000 + 1000 * (i + 1);
        return;
      }
      if (diceNumCount[i] == 2) {
        answer = 1000 + 100 * (i + 1);
        return;
      }
    }
    for (int i = diceNumCount.length - 1; i >= 0; i--) {
      if (diceNumCount[i] == 1) {
        answer = (i + 1) * 100;
        return;
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }
}
