import java.util.ArrayList;
import java.util.List;

class Solution {

  public int[] solution(int n, int s) {
    int[] answer = new int[n];
    if (n > s) {
      return new int[]{-1};
    }
    int tmp = s / n;
    int index = s - tmp * n;
    for (int i = 0; i < n - index; i++) {
      answer[i] = tmp;
    }
    for (int i = 0; i < index; i++) {
      answer[n - index + i] = tmp + 1;
    }
    return answer;
  }
}