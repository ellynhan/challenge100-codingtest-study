class Solution {

  public int solution(String s) {
    int answer = 1;

    for (int i = 0; i < s.length(); i++) {
      for (int j = i + 1; j < s.length(); j++) {
        if (answer < j - i + 1 && s.charAt(i) == s.charAt(j)) {
          boolean flag = true;
          for (int k = i + 1; k < (i + j + 1) / 2; k++) {
            if (s.charAt(k) != s.charAt(j + i - k)) {
              flag = false;
              break;
            }
          }
          if (flag) {
            answer = Math.max(answer, j - i + 1);
          }
        }
      }
    }

    return answer;
  }
}