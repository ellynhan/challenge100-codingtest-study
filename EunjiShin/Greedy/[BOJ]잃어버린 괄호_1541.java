package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LostBracket {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    StringTokenizer st = new StringTokenizer(str, "-");

    int result = 0;
    boolean isFirst = true;
    while (st.hasMoreTokens()) {
      String subStr = st.nextToken();
      int subResult = 0;
      StringTokenizer plusSt = new StringTokenizer(subStr, "+");
      while (plusSt.hasMoreTokens()) {
        subResult += Integer.parseInt(plusSt.nextToken());
      }
      if (isFirst) {
        result += subResult;
        isFirst = false;
      }
      else result -= subResult;
    }

    System.out.println(result);
  }

}
