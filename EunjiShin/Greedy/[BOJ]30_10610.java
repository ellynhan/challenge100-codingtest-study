package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Thirteen {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String N = br.readLine();

    int sum = 0;
    // DESCRIBE: 3의 배수 조건 충족하는지 카운트
    for (int i = 0; i < N.length(); i++) {
        sum += N.charAt(i) - '0';
    }

    // DESCRIBE: 3의 배수 조건과 10의 배수 조건 충족 못하면 바로 -1
    if (!N.contains("0") || sum % 3 != 0) {
      System.out.println(-1);
    }
    // DESCRIBE: 충족하면 최대값 찾기
    else {
      char[] chars = N.toCharArray();
      Arrays.sort(chars);
      for (int i = chars.length-1; i >= 0; i--) {
        System.out.print(chars[i]);
      }
    }
  }

}
