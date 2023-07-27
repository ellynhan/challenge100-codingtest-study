class Solution {

  public String solution(String s, int n) {
    StringBuilder answer = new StringBuilder();
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (c == ' ') {
        answer.append(' ');
      } else if ('a' <= c && c <= 'z') {
        answer.append((char) (((c - 'a') + n) % 26 + 'a'));
      } else if ('A' <= c && c <= 'Z') {
        answer.append((char) (((c - 'A') + n) % 26 + 'A'));
      }
    }
    return answer.toString();
  }
}