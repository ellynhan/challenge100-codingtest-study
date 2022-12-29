package Hashing15829;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  static int length = 0;

  static String string = "";
  static long result = 0;

  static long pow = 1;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    input(br);
    solve();
    print(bw);

    bw.flush();
    br.close();
    bw.close();
  }

  private static void input(BufferedReader br) throws IOException {
    length = Integer.parseInt(br.readLine());
    string = br.readLine();
  }

  private static void solve() throws IOException {
    for (int i = 0; i < length; i++) {
      result += (string.charAt(i) - 96) * pow;
      pow = (pow * 31) % 1234567891; // 곱해줄 때 마다 1234567891로 mod 연산 해서 overflow 방지
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(result % 1234567891)); // 결과도 마찬가지로 overflow 방지
  }

}
