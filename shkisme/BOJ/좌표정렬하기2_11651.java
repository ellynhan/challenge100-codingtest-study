package BOJ.좌표정렬하기2_11651;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {

  static int N;

  static List<Point> pointList = new ArrayList<>();

  public static class Point {

    private final int x;
    private final int y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public int getX() {
      return x;
    }

    public int getY() {
      return y;
    }

    @Override
    public String toString() {
      return x + " " + y;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    // System.in, System.out 보다 훨씬 빠른 BufferedReader, BufferedWriter

    input(br);
    solve();
    print(bw);

    bw.flush();
    br.close();
    bw.close();
  }

  private static void input(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; i++) {
      String[] input = br.readLine().split(" ");
      pointList.add(new Point(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
    }
  }

  private static void solve() {
    pointList.sort(new Comparator<Point>() {
      @Override
      public int compare(Point o1, Point o2) {
        if (o1.getY() == o2.getY()) {
          return o1.getX() - o2.getX();
        }
        return o1.getY() - o2.getY();
      }
    });
  }

  private static void print(BufferedWriter bw) throws IOException {
    for (Point point : pointList) {
      bw.write(point.toString() + "\n");
    }
  }
}
