class Solution {

  int[][] square;

  public int solution(int[][] board) {
    square = new int[board.length][board[0].length];

    int answer = 0;

    for (int i = 0; i < board.length; i++) {
      for (int j = 0; j < board[0].length; j++) {
        square[i][j] = board[i][j];
        if (square[i][j] != 0) {
          int prevI = i - 1;
          int prevJ = j - 1;
          if (0 <= prevI && 0 <= prevJ) {
            int tmp = ((int) Math.sqrt(
                Math.min(square[prevI][j], Math.min(square[prevI][prevJ], square[i][prevJ])))) + 1;
            square[i][j] = tmp * tmp;
          }
          answer = Math.max(answer, square[i][j]);
        }
      }
    }

    return answer;
  }
}