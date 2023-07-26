import java.util.Arrays;

class Solution {

  public String solution(String s) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.length();) {
      while (i < s.length() && s.charAt(i) == ' ') {
        sb.append(' ');
        i++;
      }
      if (i >= s.length()) {
        break;
      }
      char firstChar = s.charAt(i);
      if ('a' <= firstChar && firstChar <= 'z') {
        sb.append((char) (firstChar + ('A' - 'a')));
      } else {
        sb.append(firstChar);
      }
      i++;
      while (i < s.length() && s.charAt(i) != ' ') {
        char c = s.charAt(i);
        if ('A' <= c && c <= 'Z') {
          sb.append((char) (c - ('A' - 'a')));
        } else {
          sb.append(c);
        }
        i++;
      }
    }
    return sb.toString();
  }
}
