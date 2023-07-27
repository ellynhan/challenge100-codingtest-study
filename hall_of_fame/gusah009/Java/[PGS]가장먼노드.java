import java.util.*;

class Solution {

  List<List<Integer>> path = new ArrayList<>();
  int[] dist;
  private static final int START = 0;

  public int solution(int n, int[][] edge) {

    initPath(n, edge);

    initDist(n);

    dijkstra(START, 0);

    return getAnswer(n);
  }

  private void initPath(int n, int[][] edge) {
    for (int i = 0; i < n; i++) {
      path.add(new ArrayList<>());
    }
    for (int[] node : edge) {
      path.get(node[0] - 1).add(node[1] - 1);
      path.get(node[1] - 1).add(node[0] - 1);
    }
  }

  private void initDist(int n) {
    dist = new int[n];
    for (int i = 0; i < n; i++) {
      dist[i] = Integer.MAX_VALUE;
    }
  }

  private int getAnswer(int n) {
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] != Integer.MAX_VALUE) {
        maxValue = Math.max(maxValue, dist[i]);
      }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] == maxValue) {
        answer++;
      }
    }
    return answer;
  }

  private void dijkstra(int curr, int w) {
    if (dist[curr] <= w) {
      return;
    }
    dist[curr] = w;

    for (var next : path.get(curr)) {
      dijkstra(next, w + 1);
    }
  }
}