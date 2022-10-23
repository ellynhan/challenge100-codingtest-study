import java.util.Arrays;
import java.util.Comparator;

class Solution {

  public int solution(int[][] routes) {
    Arrays.sort(routes, Comparator.comparingInt(o -> o[1]));
    int answer = 0;
    for (int i = 0; i < routes.length; ) {
      int[] route = routes[i];
      int pivot = route[1];
      i++;
      while (i < routes.length && routes[i][0] <= pivot) {
        i++;
      }
      answer++;
    }
    return answer;
  }
}