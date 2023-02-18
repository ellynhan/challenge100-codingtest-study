import java.util.*;

class Solution {

  List<Set<Integer>> winResult = new ArrayList<>();
  List<Set<Integer>> lossResult = new ArrayList<>();
  List<Set<Integer>> newWinResult = new ArrayList<>();
  List<Set<Integer>> newLossResult = new ArrayList<>();

  public int solution(int n, int[][] results) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
      winResult.add(new HashSet<>());
      lossResult.add(new HashSet<>());
    }

    for (var result : results) {
      winResult.get(result[0] - 1).add(result[1] - 1);
      lossResult.get(result[1] - 1).add(result[0] - 1);
    }

    for (int i = 0; i < n; i++) {
      newWinResult.add(new HashSet<>(winResult.get(i)));
      newLossResult.add(new HashSet<>(lossResult.get(i)));
    }

    for (int i = 0; i < n; i++) {
      for (var next : winResult.get(i)) {
        dfs(newWinResult, winResult, i, next);
      }
      for (var next : lossResult.get(i)) {
        dfs(newLossResult, lossResult, i, next);
      }
    }

    for (int i = 0; i < n; i++) {
      if (newWinResult.get(i).size() + newLossResult.get(i).size() == n - 1) {
        answer++;
      }
    }
    return answer;
  }

  private void dfs(List<Set<Integer>> newResult, List<Set<Integer>> result, int i, int curr) {
    for (var next : result.get(curr)) {
      if (!newResult.get(i).contains(next)) {
        newResult.get(i).add(next);
        dfs(newResult, result, i, next);
      }
    }
  }
}