public class Solution {

  final static int MAX_NUM = 30;

  boolean[] lostDP = new boolean[MAX_NUM];
  boolean[] reserveDP = new boolean[MAX_NUM];

  public int solution(int n, int[] lost, int[] reserve) {
    int answer = n;

    init(lost, reserve);

    lostReserveIsSame();

    solve();

    answer = getAnswer(answer);

    return answer;
  }

  private int getAnswer(int answer) {
    for (boolean isLost : lostDP) {
      if (isLost) {
        answer--;
      }
    }
    return answer;
  }

  private void solve() {
    for (int i = 0; i < lostDP.length; i++) {
      if (lostDP[i]) {
        if (i > 0 && reserveDP[i - 1]) {
          reserveDP[i - 1] = false;
          lostDP[i] = false;
        } else if (reserveDP[i + 1]) {
          reserveDP[i + 1] = false;
          lostDP[i] = false;
        }
      }
    }
  }

  private void lostReserveIsSame() {
    for (int i = 0; i < lostDP.length; i++) {
      if (lostDP[i]) {
        if (lostDP[i] == reserveDP[i]) {
          lostDP[i] = false;
          reserveDP[i] = false;
        }
      }
    }
  }

  private void init(int[] lost, int[] reserve) {
    for (int i : lost) {
      lostDP[i - 1] = true;
    }
    for (int i : reserve) {
      reserveDP[i - 1] = true;
    }
  }
}
