package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 10448
public class Eureka {

  static int[] triNum = new int[45];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());

    makeTriNum();

    for(int i = 0; i < T; i++) {
      int n = Integer.parseInt(br.readLine());
      System.out.println(isEureka(n));
    }

  }

  public static void makeTriNum() {
    for(int i = 1; i < 45; i++) {
      triNum[i] = i * (i+1) / 2;
    }
  }

  public static int isEureka(int n) {
    for (int i = 1; i < 45; i++) {
      for (int j = 1; j < 45; j++) {
        for (int k = 1; k < 45; k++) {
          int sum = triNum[i] + triNum[j] + triNum[k];
          if (sum == n) return 1;
        }
      }
    }
    return 0;
  }

}
