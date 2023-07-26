class Solution {

  public int[] solution(int[] prices) {
    int[] answer = new int[prices.length];

    for (int curr = 0; curr < prices.length - 1; curr++) {
      int end = curr + 1;
      for (; end < prices.length - 1; end++) {
        if (prices[curr] > prices[end]) {
          break;
        }
      }
      answer[curr] = end - curr;
    }
    return answer;
  }
}
