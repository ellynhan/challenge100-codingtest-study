import java.util.Stack;

class Solution {

  Stack<Integer> stack = new Stack<>();

  public int solution(String dartResult) {
    int answer = 0;
    for (int i = 0; i < dartResult.length();) {
      int num;
      if (i < dartResult.length() - 1 && dartResult.charAt(i + 1) == '0') {
        num = 10;
        i += 2;
      } else {
        num = Integer.parseInt(String.valueOf(dartResult.charAt(i)));
        i++;
      }

      char sdt = dartResult.charAt(i);
      if (sdt == 'D') {
        num = num * num;
      } else if (sdt == 'T') {
        num = num * num * num;
      }
      i++;
      stack.add(num);

      if (i < dartResult.length() && (dartResult.charAt(i) == '*' || dartResult.charAt(i) == '#')) {
        char opt = dartResult.charAt(i);
        if (opt == '*') {
          Integer num1 = stack.pop();
          if (!stack.isEmpty()) {
            Integer num2 = stack.pop();
            stack.push(num2 * 2);
          }
          stack.push(num1 * 2);
        } else if (opt == '#') {
          Integer num1 = stack.pop();
          stack.push(-num1);
        }
        i++;
      }
    }
    return stack.stream().reduce(0, Integer::sum);
  }
}