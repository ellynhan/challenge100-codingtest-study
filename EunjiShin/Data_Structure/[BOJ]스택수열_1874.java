package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class StackSequence {

  public static void main(String[] args) throws IOException {
    Stack<Integer> stack = new Stack<>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    int n = Integer.parseInt(br.readLine());
    int start = 0;
    while(n-- > 0) {
      int num = Integer.parseInt(br.readLine());
      if (num > start) {
        for (int i = start; i < num; i++) {
          stack.push(i+1);
          sb.append("+").append("\n");
        }
        start = num;
      }
      else if (stack.peek() != num) {
        System.out.println("NO");
        return;
      }

      stack.pop();
      sb.append("-").append("\n");
      }

    System.out.println(sb);
    }
  }

