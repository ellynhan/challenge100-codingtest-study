package string.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class StringSet {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    HashSet<String> inputs = new HashSet<>();
    for (int i = 0; i < N; i++) {
      inputs.add(br.readLine());
    }

    int result = 0;
    for (int i = 0; i < M; i++) {
      if (inputs.contains(br.readLine())) {
        result++;
      }
    }

    System.out.println(result);
  }

}
