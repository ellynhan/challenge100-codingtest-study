package string.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class NeverHeardOf {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    Set<String> neverSeenOf = new HashSet<>();
    for (int i = 0; i < N; i++) {
      neverSeenOf.add(br.readLine());
    }

    List<String> neverSeenHeardOf = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      String input = br.readLine();
      if (neverSeenOf.contains(input)) {
        neverSeenHeardOf.add(input);
      }
    }

    Collections.sort(neverSeenHeardOf);
    System.out.println(neverSeenHeardOf.size());
    for (String s : neverSeenHeardOf) {
      System.out.println(s);
    }
  }

}
