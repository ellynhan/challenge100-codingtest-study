import java.util.Stack;

class Solution {

  public int solution(String s) {
    Stack<Character> stack = new Stack<>();
    for (int i = 0; i < s.length(); i++) {
      // System.out.println(stack);
      char c = s.charAt(i);
      if (stack.empty()) {
        stack.push(c);
      } else {
        Character peek = stack.peek();
        if (peek.equals(c)) {
          stack.pop();
        } else {
          stack.push(c);
        }
      }
    }
    return stack.empty() ? 1 : 0;
  }
}