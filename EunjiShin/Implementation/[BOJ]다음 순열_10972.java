package Implementation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class NextPermutation {

  public static int N;
  public static int[] array;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    N = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    array = new int[N];
    for (int i = 0; i < N; i++) {
      array[i] = Integer.parseInt(st.nextToken());
    }

    // 다음 순열 찾기
    if (nextPermutation()) {
      for (int i = 0; i < N; i++) {
        sb.append(array[i] + " ");
      }
    } else {
      sb.append("-1");
    }

    bw.write(sb.toString());
    bw.close();
    br.close();

  }

  public static boolean nextPermutation() {

    // 뒤에서부터 내려오기
    int i = N-1;
    while (i > 0 && array[i-1] >= array[i]) {
      i--;
    }

    if (i <= 0) return false;

    // swap할 인덱스 구하기 위해 한번 더!
    int j = N-1;
    while (array[j] <= array[i-1]) {
      j--;
    }

    // 스왑
    int temp = array[i-1];
    array[i-1] = array[j];
    array[j] = temp;

    // i부터 끝까지 수열 뒤집기
    int lastIndex = N-1;
    while (i < lastIndex) {
      int swapTemp = array[i];
      array[i] = array[lastIndex];
      array[lastIndex] = swapTemp;
      i++; lastIndex--;
    }

    return true;
  }

}
