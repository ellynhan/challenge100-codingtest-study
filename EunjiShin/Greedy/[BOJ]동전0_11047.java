package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CoinZero {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    int[] array = new int[N];
    int answer = 0;

    // DESCRIBE: 동전 가치 입력
    for (int i = 0; i < N; i++) {
      array[i] = Integer.parseInt(br.readLine());
    }

    // DESCRIBE: 동전 개수 찾기
    for (int i = N-1; i >= 0; i--) {
      if (array[i] <= K) {
        answer += (K/array[i]);
        K %= array[i];
      }
    }

    System.out.println(answer);
  }

}
