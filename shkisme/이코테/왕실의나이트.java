import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  static String input;
  static int count = 0, currentX, currentY;
  static int[] dx = {-2, -2, -1, 1, 2, 2, -1, 2};
  static int[] dy = {-1, 1, 2, 2, -1, 1, -2, -2};

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
    input = br.readLine();

    currentX = input.charAt(1) - '1';
    currentY = input.charAt(0) - 'a';
  }

  private static void solve() {
    int nx, ny;
    for (int i = 0; i < 8; ++i) {
      nx = currentX + dx[i];
      ny = currentY + dy[i];

      if (nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7) {
        count++;
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(count));
  }
}
