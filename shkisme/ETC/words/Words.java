package words;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Words {

  static int N, majorityValue;

  static long size = 1000000, round = 10;

  static Map<String, Integer> map = new HashMap<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    input(br);
    long start = System.currentTimeMillis();
    Entry<String, Integer> maxValue = solve();
    System.out.print("Answer = ");
    print(maxValue);
    long end = System.currentTimeMillis();
    System.out.println("[size]: " + size);
    System.out.println("[round]: " + round);
    System.out.printf("[time]: %2d ms", (end - start));

    br.close();
  }

  private static void input(BufferedReader br) throws IOException {
    // 테스트용 INPUT - 시간, 성능 측정용
    String test1 = "Test1";
    String test2 = "Test2";
    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) {
        map.put(test1, i);
      } else {
        map.put(test2, i);
      }

      if (i <= 50) {
        test1 += "*";
      }
      if (i <= 25) {
        test2 += "#";
      }
    }

    // 문제 풀이용 INPUT - 테스트 케이스 통과 O
    /*N = Integer.parseInt(br.readLine());
    majorityValue = N / 2 + 1;
    for (int i = 0; i < N; i++) {
      String word = br.readLine();
      if (map.containsKey(word)) {
        map.put(word, map.get(word) + 1);
      } else {
        map.put(word, 1);
      }
    }*/
  }

  private static Entry<String, Integer> solve() {
    return Collections.max(map.entrySet(),
        new Comparator<Entry<String, Integer>>() {
          @Override
          public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
            return o1.getValue().compareTo(o2.getValue());
          }
        });
  }

  private static void print(Entry<String, Integer> maxValue) {
    if (maxValue.getValue() >= majorityValue) {
      System.out.println(maxValue.getKey());
    } else {
      System.out.println("NONE");
    }
  }
}
