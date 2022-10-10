import java.util.Arrays;
import java.util.Comparator;

class Solution {

  int[] parents;

  public int solution(int n, int[][] costs) {
    parents = new int[n];
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    Arrays.sort(costs, Comparator.comparingInt(i -> i[2]));
    int answer = 0;
    for (int[] cost : costs) {
      if (union(cost[0], cost[1])) {
        answer += cost[2];
      }
    }
    return answer;
  }

  private boolean union(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    if (aRoot == bRoot) {
      return false;
    }
    parents[aRoot] = bRoot;
    return true;
  }

  private int find(int a) {
    if (a == parents[a]) {
      return a;
    }
    return parents[a] = find(parents[a]);
  }
}