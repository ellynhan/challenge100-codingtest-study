import static java.lang.Integer.MAX_VALUE;
import static java.lang.Integer.MIN_VALUE;
import static java.util.stream.Collectors.toList;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

  static int N, max, min, median;

  static double sum; // 반올림을 위해 double 로 선언

  static List<Integer> modeList = new ArrayList<>();

  static int[] numbers;
  /**
   * @key = 숫자
   * @value = 숫자가 나온 빈도수
   */
  static Map<Integer, Integer> map = new TreeMap<>(); // 키는 저장과 동시에 자동 오름차순으로 정렬

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    input(br);
    solve();
    print(bw);

    br.close();
    bw.close();
  }

  private static void input(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    numbers = new int[N];
    for (int i = 0; i < N; i++) {
      int input = Integer.parseInt(br.readLine());
      numbers[i] = input;
      map.compute(input, (key, value) -> (value == null) ? 1 : ++value);
    }
  }

  private static void solve() {
    sum = Arrays.stream(numbers).sum();
    max = Arrays.stream(numbers).max().orElse(MAX_VALUE);
    min = Arrays.stream(numbers).min().orElse(MIN_VALUE);
    median = Arrays.stream(numbers) // 생각보다 단순한, 중앙값 구하기 로직
        .sorted()
        .boxed()
        .collect(toList())
        .get(N / 2);

    int maxValues = map.values().stream().max(new Comparator<Integer>() {
      @Override
      public int compare(Integer o1, Integer o2) {
        return o1 - o2;
      }
    }).orElse(MAX_VALUE);

    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
      if (entry.getValue() == maxValues) {
        modeList.add(entry.getKey());
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(Math.round(sum / (N)) + "\n");
    bw.write((median) + "\n");
    if (modeList.size() != 1) {
      bw.write(modeList.get(1) + "\n");
    } else {
      bw.write(modeList.get(0) + "\n");
    }
    bw.write((max - min) + "\n");
    bw.flush();
  }
}
