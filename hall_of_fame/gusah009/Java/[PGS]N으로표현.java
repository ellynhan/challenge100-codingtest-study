import java.util.*;

class Solution {

  private static final int MAX = 9;
  private static final List<Long> poss = List.of(1L, 11L, 111L, 1111L, 11111L, 111111L, 1111111L,
      11111111L);
  Set<Long>[][] dp = new HashSet[MAX][MAX];

  public int solution(int N, int number) {
    if (N == number) {
      return 1;
    }
    initDp(N);
    return dfs(N, number, 1);
  }

  private void initDp(int N) {
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        dp[i][j] = new HashSet<>();
      }
      dp[i][i].add((long) N);
    }
  }

  private int dfs(int n, int target, int depth) {
    if (depth == MAX) {
      return -1;
    }
    for (int i = 0; i < depth; i++) {
      for (Operator op : Operator.values()) {
        for (Long a : dp[0][i]) {
          for (Long b : dp[0][depth - (i + 1)]) {
            if (op == Operator.DIVIDE && b == 0) {
              continue;
            }
            if (op == Operator.CONCAT && !isValid(n, a, b)) {
              continue;
            }
            Long result = calculate(a, b, op);
            if (result == target) {
              return depth + 1;
            }
            dp[0][depth].add(result);
          }
        }
      }
    }
    return dfs(n, target, depth + 1);
  }

  private boolean isValid(int n, Long a, Long b) {
    if (a % n != 0 || b % n != 0) {
      return false;
    }
    return poss.contains(a / n) && poss.contains(b / n);
  }


  private Long calculate(Long a, Long b, Operator o) {
    return switch (o) {
      case PLUS -> a + b;
      case MINUS -> a - b;
      case DIVIDE -> a / b;
      case MULTIPLE -> a * b;
      case CONCAT -> Long.parseLong(String.valueOf(a) + b);
    };
  }

  enum Operator {
    PLUS, MINUS, MULTIPLE, DIVIDE, CONCAT
  }

  // public static void main(String[] args) {
  //   Solution solution = new Solution();
  //   int N = 5;
  //   int number = 55;
  //   System.out.println("solution(" + N + ", " + number + ") = " + solution.solution(N, number));
  // }
}