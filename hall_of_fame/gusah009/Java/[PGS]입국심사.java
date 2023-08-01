import java.util.Arrays;

class Solution {

  public long solution(int n, int[] times) {
    Arrays.sort(times);

    long startTime = times[0];
    long endTime = (long) times[times.length - 1] * n;
    long answer = Long.MAX_VALUE;
    while (startTime <= endTime) {
      long passedImmigration = 0L;
      long currentTime = (startTime + endTime) / 2;
      for (long time : times) {
        passedImmigration += currentTime / time;
      }
      if (passedImmigration >= n) {
        answer = Math.min(answer, currentTime);
        endTime = currentTime - 1;
      } else if (passedImmigration < n) {
        startTime = currentTime + 1;
      }
    }
    return answer;
  }
}
