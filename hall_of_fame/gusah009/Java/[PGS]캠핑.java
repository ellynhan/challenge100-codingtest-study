import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

class Solution {

  Map<Integer, Integer> xMap = new HashMap<>();
  Map<Integer, Integer> yMap = new HashMap<>();
  int[][] board;
  int[][] count;

  public int solution(int n, int[][] data) {
    coordinateCompression(data);
    initBoard(data);
    initCount();

    return getAnswer(data);
  }

  private int getAnswer(int[][] data) {
    int answer = 0;
    for (int i = 0; i < data.length; i++) {
      for (int j = i + 1; j < data.length; j++) {
        int x1 = Math.min(data[i][0], data[j][0]);
        int y1 = Math.min(data[i][1], data[j][1]);
        int x2 = Math.max(data[i][0], data[j][0]) - 1;
        int y2 = Math.max(data[i][1], data[j][1]) - 1;

        if (x1 == x2 + 1 || y1 == y2 + 1) {
          continue;
        }
        
        if (x1 >= x2 || y1 >= y2) {
          answer++;
          continue;
        }

        if (count[x2][y2] - count[x2][y1] - count[x1][y2] + count[x1][y1] == 0) {
          answer++;
        }
      }
    }
    return answer;
  }

  private void initCount() {
    count = new int[xMap.size()][yMap.size()];
    count[0][0] = board[0][0];
    for (int i = 1; i < xMap.size(); i++) {
      count[i][0] = count[i - 1][0] + board[i][0];
    }
    for (int i = 1; i < yMap.size(); i++) {
      count[0][i] = count[0][i - 1] + board[0][i];
    }
    for (int i = 1; i < xMap.size(); i++) {
      for (int j = 1; j < yMap.size(); j++) {
        count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1] + board[i][j];
      }
    }
  }

  private void initBoard(int[][] data) {
    board = new int[xMap.size()][yMap.size()];
    for (int[] xy : data) {
      board[xy[0]][xy[1]] = 1;
    }
  }

  private void coordinateCompression(int[][] data) {
    Arrays.sort(data, Comparator.comparingInt(o -> o[0]));
    Integer xSeq = 0;
    for (int[] dataNum : data) {
      if (!xMap.containsKey(dataNum[0])) {
        xMap.put(dataNum[0], xSeq++);
      }
    }
    for (int i = 0; i < data.length; i++) {
      data[i][0] = xMap.get(data[i][0]);
    }
    Arrays.sort(data, Comparator.comparingInt(o -> o[1]));
    Integer ySeq = 0;
    for (int[] dataNum : data) {
      if (!yMap.containsKey(dataNum[1])) {
        yMap.put(dataNum[1], ySeq++);
      }
    }
    for (int i = 0; i < data.length; i++) {
      data[i][1] = yMap.get(data[i][1]);
    }
  }
}