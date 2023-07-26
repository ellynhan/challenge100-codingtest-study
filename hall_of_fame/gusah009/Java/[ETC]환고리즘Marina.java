import static java.lang.Math.asin;
import static java.lang.Math.sqrt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Main {

  static class Vector {

    double x;
    double y;

    public Vector(double x, double y) {
      this.x = x;
      this.y = y;
    }
  }

  static class Point {

    double x;
    double y;

    public Point(double x, double y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = inputInit();
    int N = Integer.parseInt(br.readLine());
    List<Point> polygon = getPolygon(N, br);

    List<Integer> answer = new ArrayList<>();
    solve(N, polygon, answer);

    printAnswer(answer);
  }

  private static void printAnswer(List<Integer> answer) {
    if (answer.isEmpty()) {
      System.out.println(0);
      return;
    }
    answer.forEach(System.out::println);
  }

  private static void solve(int N, List<Point> polygon, List<Integer> answer) {
    for (int n = 0; n < N; n++) {
      Point curr = polygon.get(n);
      Point prev = polygon.get((n - 1 + N) % N);
      Point next = polygon.get((n + 1) % N);
      if (getAngle(curr, prev, next) * 180 > 0) {
        answer.add(n + 1);
      }
    }
  }

  private static double getAngle(Point curr, Point prev, Point next) {
    Vector v1 = new Vector(curr.x - prev.x, curr.y - prev.y);
    Vector v2 = new Vector(curr.x - next.x, curr.y - next.y);
    return asin((v1.x * v2.y - v1.y * v2.x) /
        (sqrt(v1.x * v1.x + v1.y * v1.y) * sqrt(v2.x * v2.x + v2.y * v2.y)));
  }

  private static List<Point> getPolygon(int N, BufferedReader br) throws IOException {
    List<Point> polygon = new ArrayList<>();
    for (int n = 0; n < N; n++) {
      String[] inputCoordinate = br.readLine().split(" ");
      double x = Double.parseDouble(inputCoordinate[0]);
      double y = Double.parseDouble(inputCoordinate[1]);
      polygon.add(new Point(x, y));
    }
    return polygon;
  }

  private static BufferedReader inputInit() {
    InputStream in = System.in;
    InputStreamReader reader = new InputStreamReader(in);
    BufferedReader br = new BufferedReader(reader);
    return br;
  }
}
