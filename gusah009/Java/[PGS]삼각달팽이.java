import java.util.ArrayList;
import java.util.List;

class Solution {

  int[][] triangle = new int[1001][1001];
  int seq = 1;

  public int[] solution(int n) {
    int[] startPos = {0, 0};
    for (int size = n; size > 0; size -= 3) {
      for (int i = 0; i < size; i++) {
        triangle[startPos[0] + i][startPos[1]] = seq++;
      }

      for (int i = 1; i < size; i++) {
        triangle[startPos[0] + size - 1][startPos[1] + i] = seq++;
      }

      for (int i = 1; i < size - 1; i++) {
        triangle[startPos[0] + size - 1 - i][startPos[1] + size - 1 - i] = seq++;
      }
      startPos[0] += 2;
      startPos[1] += 1;
    }

    List<Integer> answer = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        answer.add(triangle[i][j]);
      }
    }
    return answer.stream().mapToInt(i -> i).toArray();
  }
}