package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ATM {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    int[] array = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    for (int i = 0; i< N; i++) {
      array[i] = Integer.parseInt(st.nextToken());
    }

    // DESCRIBE: 오름차순 정렬
    Arrays.sort(array);

    // DESCRIBE: 누적합 구하기
    int waitTime = 0;
    int totalWaitTime = 0;
    for (int i = 0; i<N; i++) {
      waitTime += array[i];
      totalWaitTime += waitTime;
    }

    System.out.println(totalWaitTime);

  }

}
