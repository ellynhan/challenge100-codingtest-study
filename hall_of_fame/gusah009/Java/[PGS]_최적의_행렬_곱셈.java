class Solution {

  private static final int MAX_MATRIX_SIZE = 200;
  private int[][] matrix;
  private final int[][] dp = new int[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];


  public int solution(int[][] matrix_sizes) {
    this.matrix = matrix_sizes;
    return calc(0, matrix_sizes.length);
  }

  int calc(int start, int end) {
    if (end - start == 1) {
      return 0;
    }
    if (dp[start][end] != 0) {
      return dp[start][end];
    }
    int result = Integer.MAX_VALUE / 2;
    for (int middle = start + 1; middle < end; middle++) {
      int left = calc(start, middle);
      int right = calc(middle, end);
      int current = matrix[start][0] * matrix[middle][0] * matrix[end - 1][1];
      result = Math.min(result, left + right + current);
    }
    return dp[start][end] = (result == Integer.MAX_VALUE / 2 ? 0 : result);
  }
}