import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 음료수얼려먹기 {

  static int N, M, count = 0;
  static boolean[][] visit;
  static int[][] array;
  static int[] dx = {1, 0, -1, 0};
  static int[] dy = {0, 1, 0, -1};

  static class Point{
    int x, y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

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

    array = new int[N][M];
    visit = new boolean[N][M];

    for (int i = 0; i < N; ++i) {
      String input = br.readLine();
      for (int j = 0; j < M; ++j) {
        array[i][j] = input.charAt(j) - '0';
      }
    }
  }

  private static void solve() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (visit[i][j] == false && array[i][j] == 0) {
          bfs(i, j);
          count++;
        }
      }
    }
  }

  private static void bfs(int i, int j) {
    Queue<Point> q = new LinkedList<>(); // 큐 하나 생성

    visit[i][j] = true; // 방문 표시
    q.offer(new Point(i, j));

    while (!q.isEmpty()) {
      Point poll = q.poll();
      for (int k = 0; k < 4; ++k) {
        int nx = poll.x + dx[k];
        int ny = poll.y + dy[k];
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1 || array[nx][ny] == 1 || visit[nx][ny] == true) {
          continue;
        }
        visit[nx][ny] = true;
        q.offer(new Point(nx, ny));
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(count));
  }
}
