package greedy.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Repairman {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    int count = 1;

    int N = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());
    int[] pipes = new int[N];
    st = new StringTokenizer(br.readLine(), " ");
    for (int i = 0; i < N; i++) {
      pipes[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(pipes);

    double position = pipes[0] - 0.5;
    for (int i = 1; i < N; i++) {
      if (position + L < pipes[i] + 0.5) {
        count++;
        position = pipes[i] - 0.5;
      }
    }
    System.out.println(count);
  }

}
