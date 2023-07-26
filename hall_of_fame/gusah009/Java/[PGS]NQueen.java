class Solution {

  boolean[][] board;
  int answer = 0;

  public int solution(int n) {
    board = new boolean[n][n];
    dfs(n, 0, board);
    return answer;
  }

  private void dfs(int n, int index, boolean[][] board) {
    if (index == n) {
      answer++;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!board[index][i]) {
        boolean[][] newBoard = new boolean[board.length][];
        for (int j = 0; j < board.length; j++) {
          newBoard[j] = board[j].clone();
        }
        for (int j = 0; j < n; j++) {
          newBoard[j][i] = true;
        }
        for (int j = 0; j < n; j++) {
          newBoard[index][j] = true;
        }
        for (int j = 0; index - j >= 0 && i - j >= 0; j++) {
          newBoard[index - j][i - j] = true;
        }
        for (int j = 0; index - j >= 0 && i + j < n; j++) {
          newBoard[index - j][i + j] = true;
        }
        for (int j = 0; index + j < n && i - j >= 0; j++) {
          newBoard[index + j][i - j] = true;
        }
        for (int j = 0; index + j < n && i + j < n; j++) {
          newBoard[index + j][i + j] = true;
        }
        dfs(n, index + 1, newBoard);
      }
    }
  }
}