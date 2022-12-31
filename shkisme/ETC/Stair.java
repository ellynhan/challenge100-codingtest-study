import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class Stair {
  public static void main(String[] args) throws IOException {
    new Stair().solution();
  }

  public void solution() throws IOException {
    String resourcePath = "src/main/resources/";
    File file = new File(resourcePath + "HW1_Eval_Data/08.inp");
    Scanner scanner = new Scanner(file.getAbsoluteFile(), StandardCharsets.UTF_8);
    int horizontalLength = 0;
    int verticalLength;
    int nextInt;
    List<Integer> horizontalLines = new ArrayList<>(); // X 선분 리스트 (누적값)
    List<Integer> yTemps = new ArrayList<>();
    do {
      nextInt = Integer.parseInt(scanner.next());
      horizontalLength += nextInt;
      if (nextInt != 0) {
        verticalLength = Integer.parseInt(scanner.next());

        horizontalLines.add(horizontalLength);
        yTemps.add(verticalLength);
      }
    } while (nextInt != 0);

    List<Integer> verticalLines = generateVerticalLines(yTemps); // Y 선분 리스트 (누적값)
    List<Boundary> boundaries = generateStairBoundary(horizontalLines,verticalLines); // X 경계값 클래스 리스트
    int boundaryValue = boundaries.get(boundaries.size() - 1).getXpoint(); // 한계점 (X의 최대 누적값)

    while (scanner.hasNext()) {
      int xPoint = scanner.nextInt();
      int yPoint = scanner.nextInt();

      if (xPoint > boundaryValue) {
        System.out.println("out"); // 한계점(X의 최대 누적값)을 넘어가면 자동 OUT
        continue;
      }
      for (Boundary boundary : boundaries) {
        Position Xposition = judgeXposition(xPoint, boundary);
        if (Xposition == Position.IN){
          printPositionWhenIn(yPoint, boundary);
          break;
        }
        if (Xposition == Position.ON){
          printPositionWhenOn(yPoint, boundary);
          break;
        }
      }
    }
  }
  // Y 선분 리스트 생성 함수
  private List<Integer> generateVerticalLines(List<Integer> yTemps) {
    List<Integer> verticalLines = new ArrayList<>();
    Collections.reverse(yTemps);
    int ySum = 0;
    for (int y : yTemps) {
      ySum += y;
      verticalLines.add(ySum);
    }
    Collections.reverse(verticalLines);
    verticalLines.add(0);
    return verticalLines;
  }
  // 계단의 경계점 클래스 리스트 생성 함수(경계점 == 계단이 내려가는 지점)
  private List<Boundary> generateStairBoundary(List<Integer> horizontalLines,
      List<Integer> verticalLines) {
    List<Boundary> boundaries = new ArrayList<>();
    for (int i = 0; i < horizontalLines.size(); i++) {
      int maxPoint = verticalLines.get(i);
      int minPoint = verticalLines.get(i + 1);
      boundaries.add(new Boundary(horizontalLines.get(i), maxPoint, minPoint));
    }
    return boundaries;
  }
  // X 값이 경계값보다 작을 때 프린트 함수
  private void printPositionWhenIn(int yPoint, Boundary boundary) {
    if (yPoint < boundary.getMaxPoint()) {
      System.out.println("in");
    } else if (yPoint == boundary.getMaxPoint()) {
      System.out.println("on");
    } else {
      System.out.println("out");
    }
  }
  // X 값이 경계값일 때 프린트 함수
  private void printPositionWhenOn(int yPoint, Boundary boundary) {
    if (yPoint < boundary.getMinPoint()) {
      System.out.println("in");
    } else if (yPoint > boundary.getMaxPoint()) {
      System.out.println("out");
    } else {
      System.out.println("on");
    }
  }
  // X 값이 경계값 안쪽인지, 경계값인지 판별하는 함수
  private Position judgeXposition(int xPoint, Boundary boundary) {
    if (xPoint < boundary.getXpoint()) {
      return Position.IN;
    }
    if (xPoint == boundary.getXpoint()) {
      return Position.ON;
    }
    return Position.OUT;
  }

}
enum Position {
  ON, IN, OUT;
}

class Boundary {

  private final int xPoint;
  private final int maxPoint;
  private final int minPoint;

  public Boundary(int xPoint, int maxPoint, int minPoint) {
    this.xPoint = xPoint;
    this.maxPoint = maxPoint;
    this.minPoint = minPoint;
  }

  public int getXpoint() {
    return xPoint;
  }

  public int getMaxPoint() {
    return maxPoint;
  }

  public int getMinPoint() {
    return minPoint;
  }

}
