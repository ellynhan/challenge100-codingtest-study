package PNU_Algorithm.deck;

import static PNU_Algorithm.deck.Message.ANSWER;
import static PNU_Algorithm.deck.Message.NO_ANSWER;
import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Deck {

  /**
   * 공간복잡도는 O(1)을 가져야 한다. 배열, 또는 이와 유사한 기억 자료구조를 사용해서는 안된다. 제한 시간 1초
   */
  static File file = new File("src/main/resources/PNU_Algorithm/deck/05.inp");
  static int N;
  static long sum = 0, count = 0, flag = 1;

  static String line;

  public static void main(String[] args) throws IOException {
    /**
     * 01.inp -> 3, 6 (O)
     * 02.inp -> 56 (O) // 한 개만 잃어버렸을 경우, 쉽다.
     * 03.inp -> 24, 56 (O) // 문제는 두 개 이상 잃어버린 경우.
     * 04.inp -> 1234 (O) // 한 개만 잃어버렸을 경우, N == 9999 일때 -> time : 5ms
     * 05.inp -> 2345, 6789 (TIME OUT -> 해결) // 두 개 이상 잃어버린 경우, N == 9999 일때
     * 5번은 Scanner 로 입력받던 방식을 BufferedReader 로 입력받았더니 해결 (time : 2212 ms -> 309 ms)
     */
    BufferedReader br = new BufferedReader(new FileReader(file.getAbsoluteFile()));
    long start = System.currentTimeMillis();
    inputFirst(br);
    br.close();
    if (count == N - 2) {
      inputSecond();
    }
    print();
    long end = System.currentTimeMillis();
    System.out.printf("[TIME] : %d ms", end - start);
  }

  private static void inputFirst(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    for (int i = 1; i <= N; i++) {
      sum += i;
    }
    while ((line = br.readLine()) != null) {
      int card = Integer.parseInt(line);
      count++;
      sum -= card;
    }
  }

  private static void inputSecond() throws IOException {
    for (int i = 1; i <= N / 2; i++) {
      flag = i;
      if (judgeAnswer() == ANSWER) {
        break;
      }
    }
  }

  private static Message judgeAnswer() throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(file.getAbsoluteFile()));
    br.readLine();
    while ((line = br.readLine()) != null) {
      int input = Integer.parseInt(line);
      if (input == sum - flag) {
        return NO_ANSWER;
      }
    }
    br.close();
    return ANSWER;
  }

  private static void print() {
    if (count == N - 1) {
      System.out.println(sum);
    } else {
      System.out.println(min(flag, sum - flag));
      System.out.println(max(flag, sum - flag));
    }
  }
}
