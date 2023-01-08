import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class Main {

  static int N, M;

  static Map<String, Integer> map = new HashMap<>();

  static String[] array;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    array = new String[N];
    for (int i = 0; i < N; ++i) {
      String input = br.readLine();
      map.put(input, i + 1);
      array[i] = input;
    }
    for (int i = 0; i < M; ++i) {
      String input = br.readLine();
      if (Character.isDigit(input.charAt(0))) {
        bw.write(array[Integer.parseInt(input) - 1] + "\n");
      } else {
        bw.write(map.get(input) + "\n");
      }
    }

    bw.flush();
    br.close();
    bw.close();
  }
}
