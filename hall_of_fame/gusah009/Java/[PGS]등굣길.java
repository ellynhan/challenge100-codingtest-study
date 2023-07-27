class Solution {

  private static final int MOD_NUM = 1_000_000_007;

  int[][] board = new int[100][100];

  public int solution(int m, int n, int[][] puddles) {
    if (puddles[0].length != 0) {
      for (int[] puddle : puddles) {
        board[puddle[1] - 1][puddle[0] - 1] = -1;
      }
    }

    for (int i = 0; i < n; i++) {
      if (board[i][0] == -1) {
        break;
      }
      board[i][0] = 1;
    }
    for (int i = 0; i < m; i++) {
      if (board[0][i] == -1) {
        break;
      }
      board[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (board[i][j] != -1) {
          int up = board[i - 1][j] == -1 ? 0 : board[i - 1][j];
          int left = board[i][j - 1] == -1 ? 0 : board[i][j - 1];
          board[i][j] = (up + left) % MOD_NUM;
        }
      }
    }
    
    return board[n - 1][m - 1];
  }
}