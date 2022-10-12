class Solution {

  public int[] solution(int brown, int yellow) {
    int[] answer = {};
    brown /= 2;
    for (int i = brown; i >= 2; i--) {
      if (yellow == (i - 2) * (brown - i)) {
        answer = new int[]{i, 2 + brown - i};
        break;
      }
    }
    return answer;
  }
}