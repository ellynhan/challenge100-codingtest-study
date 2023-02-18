class Solution {

  static int[][] dir = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  static int[][] dp;
  static int[] seq = new int[]{0, 2, 1, 3};
  static int answer = Integer.MAX_VALUE;
  static int N;
  static boolean[][] isVisited;

  public int solution(int[][] board) {
    N = board.length;
    isVisited = new boolean[N][N];
    dp = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = Integer.MAX_VALUE - 1000;
      }
    }

    dp[0][0] = 0;
    dfs(board, 0, 0, -1, 0);
    return answer;
  }

  void dfs(int[][] board, int i, int j, int prevDir, int currentCost) {
    if (i == N - 1 && j == N - 1) {
      answer = Math.min(answer, currentCost);
      return;
    }

    if (currentCost >= answer) {
      return;
    }

    if (currentCost > dp[i][j] + 500) {
      return;
    }
    dp[i][j] = currentCost;
    
    for (int k : seq) {
      int[] d = dir[k];
      int nextI = i + d[0];
      int nextJ = j + d[1];

      if (0 <= nextI && nextI < N &&
          0 <= nextJ && nextJ < N &&
          !isVisited[nextI][nextJ] &&
          board[nextI][nextJ] != 1) {
        isVisited[nextI][nextJ] = true;
        if (prevDir == -1) {
          dfs(board, nextI, nextJ, k, currentCost + 100);
        } else {
          dfs(board, nextI, nextJ, k, currentCost + 100 + 500 * (prevDir % 2 != k % 2 ? 1 : 0));
        }
        isVisited[nextI][nextJ] = false;
      }
    }
  }
}