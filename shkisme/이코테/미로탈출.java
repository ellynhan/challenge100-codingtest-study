import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미로탈출 {

  static int N, M, answer;
  static int[][] array;
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, -1, 1};

  static class Point {

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
    for (int i = 0; i < N; ++i) {
      String input = br.readLine();
      for (int j = 0; j < M; ++j) {
        array[i][j] = input.charAt(j) - '0';
      }
    }
  }

  private static void solve() {
    answer = bfs(0, 0);
  }

  private static int bfs(int i, int j) {
    Queue<Point> q = new LinkedList<>(); // 큐 하나 생성
    q.offer(new Point(i, j));

    while (!q.isEmpty()) {
      Point poll = q.poll();
      for (int k = 0; k < 4; ++k) {
        int nx = poll.x + dx[k];
        int ny = poll.y + dy[k];
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
          continue; // 벽인 경우 무시
        }
        if (array[nx][ny] == 0) { // ps. 네이밍은 array 보다는 graph 가 좋겠다.
          continue; // 괴물이 있는 곳일 경우 무시
        }
        if (array[nx][ny] == 1) { // 처음 방문하는 경우에는 최단 거리를 기록한다.
          array[nx][ny] = array[poll.x][poll.y] + 1;
          q.offer(new Point(nx, ny));
        }
      }
    }
    return array[N - 1][M - 1];
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }
}
