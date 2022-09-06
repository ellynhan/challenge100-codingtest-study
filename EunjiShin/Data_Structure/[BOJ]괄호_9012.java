package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Bracket {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    Integer t = Integer.parseInt(br.readLine());

    for (int i = 0; i<t; i++) {
      count(br.readLine());
    }
  }

  public static void count(String str) {
    int left = 0;
    int right = 0;

    for (int i = 0; i < str.length(); i++) {
      if (str.charAt(i) == '(') left++;
      else right++;

      if (right > left) {
        System.out.println("NO");
        return;
      }
    }

    if (right != left) System.out.println("NO");
    else System.out.println("YES");
  }

}
