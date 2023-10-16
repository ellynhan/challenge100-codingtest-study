package string.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class chromosome {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int T = Integer.parseInt(br.readLine());
    for (int i = 0; i < T; i++) {
      checkRule(br.readLine());
    }
  }

  public static void checkRule(String input) {
    int a = input.indexOf("A");
    int f = input.indexOf("F");
    int c = input.indexOf("C");

    int lastA = input.lastIndexOf("A");
    int lastF = input.lastIndexOf("F");

    int lastIndex = input.length()-1;
    if (input.charAt(lastIndex) == 'A' || input.charAt(lastIndex) == 'F' || input.charAt(lastIndex) == 'C') {
      if (a < f && f < c && (lastA == f-1 && lastF == c-1)) {
        System.out.println("Infected!");
        return;
      }
    }
    System.out.println("Good");
  }

}
