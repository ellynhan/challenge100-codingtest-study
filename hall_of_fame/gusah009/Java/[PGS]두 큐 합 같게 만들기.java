import java.util.Arrays;

class Solution {

  public int solution(int[] queue1, int[] queue2) {
    int q1 = 0, q2 = 0;
    long sum1 = Arrays.stream(queue1).sum();
    long sum2 = Arrays.stream(queue2).sum();
    int[] myQueue1 = new int[queue1.length + queue2.length];
    int[] myQueue2 = new int[queue1.length + queue2.length];
    System.arraycopy(queue1, 0, myQueue1, 0, queue1.length);
    System.arraycopy(queue2, 0, myQueue1, queue1.length, queue2.length);
    System.arraycopy(queue2, 0, myQueue2, 0, queue2.length);
    System.arraycopy(queue1, 0, myQueue2, queue2.length, queue1.length);
    int answer = 0;

    while (q1 < myQueue1.length && q2 < myQueue2.length) {
      if (sum1 > sum2) {
        sum2 += myQueue1[q1];
        sum1 -= myQueue1[q1];
        q1++;
      } else if (sum1 < sum2) {
        sum1 += myQueue2[q2];
        sum2 -= myQueue2[q2];
        q2++;
      } else if (sum1 == sum2) {
        return answer;
      }
      answer++;
    }

    return -1;
  }
}