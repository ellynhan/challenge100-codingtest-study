package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class WordFlip {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    Stack<Character> stack = new Stack<>();

    boolean flag = false;

    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '<') {
          while (!stack.empty()) {
            System.out.print(stack.pop());
          }
        flag = true;
      }

      else if (s.charAt(i) == '>') {
        flag = false;
        System.out.print(s.charAt(i));
      }

      else if (s.charAt(i) == ' ' && !flag) {
          while (!stack.empty()) {
            System.out.print(stack.pop());
          }
        System.out.print(s.charAt(i));
      }

      else if (!flag){
        stack.push(s.charAt(i));
      }

      else if (flag) {
        System.out.print(s.charAt(i));
      }
    }

    while (!stack.empty()) {
      System.out.print(stack.pop());
    }
  }

}
