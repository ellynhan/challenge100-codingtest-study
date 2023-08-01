class Solution {

  int seq = 0;

  public String solution(int n, int t, int m, int p) {
    StringBuilder answer = new StringBuilder();
    int memSeq = 0;
    while (answer.length() < t) {
      String s = Integer.toString(seq++, n);
      for (int i = 0; i < s.length(); i++) {
        if (answer.length() < t && memSeq % m == p - 1) {
          answer.append(s.charAt(i));
        }
        memSeq++;
      }
    }
    return answer.toString().toUpperCase();
  }
}