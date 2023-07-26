import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {

  static int N;
  static int[] arr;
  static Map<Integer, Integer> map = new HashMap<>();
  static int answer = 0;

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
    N = Integer.parseInt(br.readLine());
    arr = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
    map = new HashMap<>(arr.length);
  }

  private static void solve() {
    int[] sortedArr = arr.clone();
    Arrays.sort(sortedArr);
    for (int i = 0; i < arr.length; i++) {
      map.put(arr[i], i);
    }
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] != sortedArr[i]) {
        int change = map.get(sortedArr[i]);
        map.put(arr[i], change);
        map.put(arr[change], i);
        int tmp = arr[i];
        arr[i] = arr[change];
        arr[change] = tmp;
        answer++;
      }
    }
  }

  private static void print(BufferedWriter bw) throws IOException {
    bw.write(String.valueOf(answer));
  }
}