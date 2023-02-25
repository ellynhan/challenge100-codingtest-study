import static java.lang.Math.min;

import java.util.ArrayList;
import java.util.List;

class Solution {

  int[][] board = new int[100][100];

  public int[] solution(int rows, int columns, int[][] queries) {
    List<Integer> answer = new ArrayList<>();
    initBoard(rows, columns);
    for (var query : queries) {
      int x1 = query[0] - 1;
      int y1 = query[1] - 1;
      int x2 = query[2] - 1;
      int y2 = query[3] - 1;
      rotate(x1, y1, x2, y2);
      answer.add(find(x1, y1, x2, y2));

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          System.out.printf(" %2d", board[i][j]);
        }
        System.out.println();
      }
    }
    return answer.stream().mapToInt(i -> i).toArray();
  }

  private Integer find(int x1, int y1, int x2, int y2) {
    int result = Integer.MAX_VALUE;
    for (int x = x1; x < x2; x++) {
      result = min(result, board[x][y1]);
    }
    for (int y = y1; y < y2; y++) {
      result = min(result, board[x2][y]);
    }
    for (int x = x2; x > x1; x--) {
      result = min(result, board[x][y2]);
    }
    for (int y = y2; y > y1; y--) {
      result = min(result, board[x1][y]);
    }
    return result;
  }

  private void rotate(int x1, int y1, int x2, int y2) {
    int tmp = board[x1][y1];
    for (int x = x1; x < x2; x++) {
      board[x][y1] = board[x + 1][y1];
    }
    for (int y = y1; y < y2; y++) {
      board[x2][y] = board[x2][y + 1];
    }
    for (int x = x2; x > x1; x--) {
      board[x][y2] = board[x - 1][y2];
    }
    for (int y = y2; y > y1; y--) {
      board[x1][y] = board[x1][y - 1];
    }
    board[x1][y1 + 1] = tmp;
  }

  private void initBoard(int rows, int columns) {
    int count = 1;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        board[i][j] = count++;
      }
    }
  }
}