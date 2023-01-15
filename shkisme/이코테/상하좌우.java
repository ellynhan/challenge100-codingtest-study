package 이코테;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.Arrays;

public class Main{

  static int N, currentX = 1, currentY = 1;
  static String[] orders;
  static char[] orderType = {'L', 'R', 'U', 'D'};
  static int[] dx = {0, 0, -1, 1};
  static int[] dy = {-1, 1, 0, 0};

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
    orders = br.readLine().split(" ");
  }

  private static void solve() {
    for (String order : orders) {
      char type = order.charAt(0);

      int nx = -1, ny = -1;
      for (int j = 0; j < 4; ++j) {
        if (type == orderType[j]) {
          nx = currentX + dx[j];
          ny = currentY + dy[j];
          break;
        }
      }
      if (nx < 1 || ny < 1 || nx > N || ny > N) {
        continue;
      }

      currentX = nx;
      currentY = ny;
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(currentX + " " + currentY);
  }

}
