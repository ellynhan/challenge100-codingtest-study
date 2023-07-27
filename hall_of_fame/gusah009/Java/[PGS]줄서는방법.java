import java.util.ArrayList;
import java.util.List;

class Solution {

  static boolean[] selected;
  static long[] facto = new long[21];
  static long N, K;

  public int[] solution(int n, long k) {
    int[] answer = new int[n];
    selected = new boolean[n];
    N = n;
    K = k;
    factorial(n);

    int i = 0;
    while (K != 1) {
      long fac = facto[(int) (N - i - 1)];
      for (int j = 0; j < N; j++) {
        if (selected[j]) {
          continue;
        }

        if (K > fac) {
          K -= fac;
          continue;
        }

        selected[j] = true;
        answer[i] = j + 1;
        break;
      }
      i++;
    }
    for (int a = 0; a < selected.length; a++) {
      if (!selected[a]) {
        answer[i++] = a + 1;
      }
    }

    return answer;
  }

  void factorial(int n) {
    facto[0] = 1;
    facto[1] = 1;
    for (int i = 2; i <= n; i++) {
      facto[i] = facto[i - 1] * i;
    }
  }
}