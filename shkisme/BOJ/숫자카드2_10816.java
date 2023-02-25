package BOJ.silver.숫자카드2_10816;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

  static int N, M;

  static Map<Integer, Integer> map = new HashMap<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());
    StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");
    for (int i = 0; i < N; ++i) {
      int key = Integer.parseInt(st1.nextToken());
      map.put(key, map.getOrDefault(key, 0) + 1);
    }

    M = Integer.parseInt(br.readLine());
    StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
    for (int i = 0; i < M; ++i) {
      bw.write(map.getOrDefault(Integer.parseInt(st2.nextToken()), 0) + " ");
    }

    bw.flush();
    br.close();
    bw.close();
  }
}
