import java.util.Stack;

class Solution {

  Stack<Integer> stack = new Stack<>();

  public int solution(int[][] board, int[] moves) {
    int answer = 0;
    for (int move : moves) {
      move -= 1;
      for (int i = 0; i < board.length; i++) {
        if (board[i][move] != 0) {
          if (!stack.isEmpty() && stack.peek() == board[i][move]) {
            stack.pop();
            answer += 2;
          } else {
            stack.add(board[i][move]);
          }
          board[i][move] = 0;
          break;
        }
      }
    }
    return answer;
  }
}