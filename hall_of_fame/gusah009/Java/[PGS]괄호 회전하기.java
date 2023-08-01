import java.util.Stack;

class Solution {

  public int solution(String s) {
    int answer = 0;

    StringBuilder sb = new StringBuilder(s);
    for (int i = 0; i < s.length(); i++) {
      char swapChar = sb.charAt(0);
      sb.deleteCharAt(0);
      sb.append(swapChar);
      Stack<Character> bracket = new Stack<>();

      int j = 0;
      for (; j < s.length(); j++) {
        char c = sb.charAt(j);
        if (c == '[') {
          bracket.add(c);
        } else if (c == ']') {
          if (bracket.empty() || bracket.pop() != '[') {
            break;
          }
        } else if (c == '{') {
          bracket.add(c);
        } else if (c == '}') {
          if (bracket.empty() || bracket.pop() != '{') {
            break;
          }
        } else if (c == '(') {
          bracket.add(c);
        } else if (c == ')') {
          if (bracket.empty() || bracket.pop() != '(') {
            break;
          }
        }
      }
      if (bracket.empty() &&
          j == s.length()) {
        answer++;
      }
    }
    return answer;
  }
}