class Solution {

  public int solution(String s) {
    int answer = Integer.MAX_VALUE;

    for (int cutSize = 1; cutSize <= s.length(); cutSize++) {
      int len = s.length();
      for (int i = 0; isInRange(s, cutSize, i); ) {
        String repeatStr = s.substring(i, i + cutSize);
        int repeatCount = 1;
        i += cutSize;
        while (isInRange(s, cutSize, i) && repeatStr.equals(s.substring(i, i + cutSize))) {
          len -= cutSize;
          i += cutSize;
          repeatCount++;
        }
        if (repeatCount != 1) {
          len += String.valueOf(repeatCount).length();
        }
      }
      answer = Math.min(answer, len);
    }
    return answer;
  }

  private boolean isInRange(String s, int cutSize, int i) {
    return i < s.length() - cutSize + 1;
  }
}