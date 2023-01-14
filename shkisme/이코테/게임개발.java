import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  static int N, M, currentX, currentY, currentD, count = 1;
  static int[] dx = {-1, 0, 1, 0};
  static int[] dy = {0, 1, 0, -1};
  static int[][] map;

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

    st = new StringTokenizer(br.readLine());
    currentX = Integer.parseInt(st.nextToken());
    currentY = Integer.parseInt(st.nextToken());
    currentD = Integer.parseInt(st.nextToken());

    map = new int[N][M];
    for (int i = 0; i < N; ++i) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; ++j) {
        map[i][j] = Integer.parseInt(st.nextToken());
      }
    }
  }

  private static void solve() {
    int nx, ny;
    while (true) {
      if (isGo()) {
        turnLeft();
        nx = dx[currentD] + currentX;
        ny = dy[currentD] + currentY;
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) { // map 바깥이면
          continue;
        }
      } else {
        nx = currentX - dx[currentD]; // 뒤로 한칸
        ny = currentY - dy[currentD];
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1
            || map[nx][ny] != 0) { // 뒤가 바다 or 가본 칸 or 바깥 이라면
          break; // 멈추기
        }
      }
      currentX = nx;
      currentY = ny;
      map[currentX][currentY] = 2;
      count++;
    }
  }

  private static boolean isGo() {
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
      nx = dx[i] + currentX;
      ny = dy[i] + currentY;
      if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) { // map 바깥이면
        continue;
      }
      if (map[nx][ny] == 0) { // 안 가본 육지 칸이 하나라도 있으면
        return true;
      }
    }
    return false;
  }

  private static void turnLeft() {
    if (currentD == 3) {
      currentD = 0;
    } else {
      currentD++;
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(count));
  }
}
