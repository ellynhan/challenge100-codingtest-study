class Solution {

  private static int TARGET;

  public int solution(int[] numbers, int target) {
    TARGET = target;
    int answer = dfs(numbers, 0, 0);

    return answer;
  }

  private int dfs(int[] numbers, int depth, int prevResult) {
    int result = 0;

    if (depth == numbers.length) {
      if (prevResult == TARGET) {
        return 1;
      }
      return 0;
    }

    result += dfs(numbers, depth + 1, prevResult + numbers[depth]);
    result += dfs(numbers, depth + 1, prevResult - numbers[depth]);

    return result;
  }
}
