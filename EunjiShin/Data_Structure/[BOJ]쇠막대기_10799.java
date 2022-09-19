package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class IronStick {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    Stack<Integer> stack = new Stack<>();
    int result = 0;

    for (int i=0; i<str.length(); i++) {
      if (str.charAt(i) == '(') stack.push(i);
      else {
        if (i-1 == stack.pop()) result += stack.size();
        else result += 1;
      }
    }

    System.out.println(result);

  }

}
