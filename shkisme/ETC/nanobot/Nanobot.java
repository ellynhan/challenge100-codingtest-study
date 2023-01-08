package PNU_Data_Structure.nanobot;

import static PNU_Data_Structure.nanobot.Direction.Down;
import static PNU_Data_Structure.nanobot.Direction.Left;
import static PNU_Data_Structure.nanobot.Direction.Right;
import static PNU_Data_Structure.nanobot.Direction.Up;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;
import java.util.Scanner;

public class Nanobot {

  int N, M, number;

  Map<Integer, Coordinate> map = new HashMap<>();

  Integer[] coordinate = new Integer[2];

  public Map<Integer, Coordinate> getMap() {
    return map;
  }

  public int getNumber() {
    return number;
  }

  public Integer[] getCoordinate() {
    return coordinate;
  }

  public static class Coordinate {

    private final int x;
    private final int y;

    public Coordinate(int x, int y) {
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
      return "Coordinate{" +
          "x=" + x +
          ", y=" + y +
          '}';
    }
  }

  public void run(Scanner scanner) {
    inputGridSize(scanner);
    solve();
    inputProblem(scanner);
  }

  void inputGridSize(Scanner scanner) {
    String[] s = scanner.nextLine().split(" ");
    N = Integer.parseInt(s[0]);
    M = Integer.parseInt(s[1]);
  }

  void inputProblem(Scanner scanner) {
    String[] input = scanner.nextLine().split(" ");
    coordinate[0] = Integer.parseInt(input[0]);
    coordinate[1] = Integer.parseInt(input[1]);
    number = Integer.parseInt(scanner.nextLine());
  }

  void solve() {
    // initial
    int last = N * M;
    int xRightFlag = N, yUpFlag = M;
    int xLeftFlag = 2, yDownFlag = 1;
    int xValue = 1, yValue = 1;
    Direction direction = Up;

    for (int i = 1; i <= last; i++) {
      map.put(i, new Coordinate(xValue, yValue));
      if (direction == Up) {
        if (yValue == yUpFlag) {
          direction = Right;
          yUpFlag--;
        } else {
          yValue++;
        }
      }
      if (direction == Right) {
        if (xValue == xRightFlag) {
          direction = Down;
          xRightFlag--;
        } else {
          xValue++;
        }
      }
      if (direction == Down) {
        if (yValue == yDownFlag) {
          direction = Left;
          yDownFlag++;
        } else {
          yValue--;
        }
      }
      if (direction == Left) {
        if (xValue == xLeftFlag) {
          direction = Up;
          xLeftFlag++;
          yValue++; // 한 바퀴 돌았다면 y 값을 1 증가시켜 줘야함.
        } else {
          xValue--;
        }
      }
    }
  }

  public void print() {
    Optional<Entry<Integer, Coordinate>> first = map.entrySet()
        .stream()
        .filter(integerCoordinateEntry -> integerCoordinateEntry.getValue().getX() == coordinate[0]
            && integerCoordinateEntry.getValue().getY() == coordinate[1])
        .findFirst();
    System.out.println(first.get().getKey());
    System.out.println(map.get(number).getX() + " " + map.get(number).getY());
  }
}
