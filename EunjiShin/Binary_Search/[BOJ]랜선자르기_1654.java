package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CutLan {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    int k = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());

    // 가진 랜선의 길이 입력
    ArrayList<Integer> list = new ArrayList<>();
    for (int i = 0; i < k; i++) {
      list.add(Integer.parseInt(br.readLine()));
    }

    long start = 1;
    long end = Collections.max(list);
    long mid;

    while (start <= end) {
      int cnt = 0;
      mid = (start + end) / 2;
      for (int i = 0; i < list.size(); i++) {
        cnt += (list.get(i) / mid);
      }
      if (cnt < n) end = mid -1;
      else start = mid + 1;
    }
    System.out.println(end);

  }
}
