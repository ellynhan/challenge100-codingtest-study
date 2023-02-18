import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class StackOne {

  public static void main(String[] args) throws IOException {
    Stack<Integer> stack = new Stack<>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    int N = Integer.parseInt(br.readLine());

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      switch (st.nextToken()) {
        case "push" :
          stack.push(Integer.parseInt(st.nextToken()));
          break;
        case "pop" :
          if (stack.empty()) sb.append("-1" + "\n");
          else {
            sb.append(stack.peek()).append("\n");
            stack.pop();
          }
          break;
        case "size" :
          sb.append(stack.size()).append("\n");
          break;
        case "empty" :
          if (stack.empty()) sb.append("1" + "\n");
          else sb.append("0" + "\n");
          break;
        case "top" :
          if (stack.empty()) sb.append("-1" + "\n");
          else sb.append(stack.peek()).append("\n");
          break;
        default:
          break;
      }
    }
    System.out.println(sb);
  }
}