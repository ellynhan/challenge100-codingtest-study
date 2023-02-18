package Implementation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Set {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;
    int M = Integer.parseInt(br.readLine());
    int S = 0;

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine(), " ");
      String operator = st.nextToken();
      int operand;

      switch (operator) {
        case "add":
          operand = Integer.parseInt(st.nextToken());
          S = S | (1 << (operand-1));
          break;
        case "remove" :
          operand = Integer.parseInt(st.nextToken());
          S = S & ~(1 << (operand-1));
          break;
        case "check" :
          operand = Integer.parseInt(st.nextToken());
          sb.append((S & (1 << (operand-1))) != 0 ? "1\n" : "0\n");
          break;
        case "toggle" :
          operand = Integer.parseInt(st.nextToken());
          S = S ^ (1<<(operand-1));
          break;
        case "all" :
          S = S | (~0);
          break;
        case "empty" :
          S &= 0;
          break;
        default:
          break;
      }
    }

    bw.write(sb.toString());
    bw.close();
    br.close();
  }

}
