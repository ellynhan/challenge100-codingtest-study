package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HolicHoseokOdd {

  static int MAX = Integer.MIN_VALUE;
  static int MIN = Integer.MAX_VALUE;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String n = br.readLine();
    split(n, 0);
    System.out.printf("%d %d", MIN, MAX);
  }

  // 입력 숫자 자르면서 새로운 숫자 만드는 메소드
  private static void split(String n, int cnt) {
    // 일단 현재 숫자에서 홀수 개수 구하기
    cnt += countOdd(n);
    int length = n.length();
    int newNumber;

    // 한자리면 암것도 못하고 종료
    if (length == 1) {
      // 한 글자 될 때마다 최대, 최소 갱신
      MAX = Math.max(MAX, cnt);
      MIN = Math.min(MIN, cnt);
    }
    // 두자리면 두개로 나눠서 새로웃 숫자 구하기
    else if (length == 2) {
     newNumber = (n.charAt(0) - '0') + (n.charAt(1) - '0');
     split(Integer.toString(newNumber), cnt);
    }
    // 세자리 이상이면 최소&최대 찾을 때까지 임의의 위치에서 잘라서 홀수 개수 구하기
    else {
      // 가능한 경우 다 해보면서 최대최소 갱신하면 됨
      for (int i = 0; i <= length - 3; i++) {
        for (int j = i+1; j <= length - 2; j++) {
          String s1 = n.substring(0, i+1);
          String s2 = n.substring(i+1, j+1);
          String s3 = n.substring(j+1, length);
          newNumber = Integer.parseInt(s1) + Integer.parseInt(s2) + Integer.parseInt(s3);
          split(Integer.toString(newNumber), cnt);
        }
      }

    }

  }

  // 자리수별 홀수 개수 세는 메소드
  private static int countOdd(String n) {
    int count = 0;
    for (int i = 0; i < n.length(); i++) {
      if ((n.charAt(i) - '0') % 2 == 1) count++;
    }
    return count;
  }

}
