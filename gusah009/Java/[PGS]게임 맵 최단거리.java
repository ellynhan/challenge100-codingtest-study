import java.util.*;

class Solution {

  private static final int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public int solution(int[][] maps) {
    int answer = -1;
    Position target = new Position(maps.length - 1, maps[0].length - 1, 0);

    Queue<Position> positionQueue = new LinkedList<>();
    positionQueue.add(Position.START);
    Position.START.setVisited(maps);
    while (!positionQueue.isEmpty()) {
      Position currPosition = positionQueue.poll();
      if (currPosition.equals(target)) {
        answer = currPosition.count;
        break;
      }
      for (var d : dir) {
        Position nextPosition = currPosition.getNextPosition(d);
        if (nextPosition.isValid(maps)) {
          nextPosition.setVisited(maps);
          positionQueue.add(nextPosition);
        }
      }
    }
    return answer;
  }


  static class Position {

    @Override
    public String toString() {
      return "Position{" +
          "x=" + x +
          ", y=" + y +
          ", count=" + count +
          '}';
    }

    static final Position START = new Position(0, 0, 1);

    int x;
    int y;
    int count;

    public Position(int x, int y, int count) {
      this.x = x;
      this.y = y;
      this.count = count;
    }

    public Position getNextPosition(int[] d) {
      return new Position(x + d[0], y + d[1], count + 1);
    }

    public boolean isValid(int[][] maps) {
      return 0 <= x && x < maps.length &&
          0 <= y && y < maps[0].length &&
          maps[x][y] != 0;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (!(o instanceof Position)) {
        return false;
      }
      Position position = (Position) o;
      return x == position.x && y == position.y;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }

    public void setVisited(int[][] maps) {
      maps[x][y] = 0;
    }
  }
}