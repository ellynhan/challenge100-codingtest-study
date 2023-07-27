import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

class Solution {

  public long solution(int n, int[] works) {
    PriorityQueue<Integer> pq = Arrays.stream(works)
        .boxed()
        .collect(Collectors.toCollection(() -> new PriorityQueue<>(Collections.reverseOrder())));

    while (!pq.isEmpty() && n != 0) {
      Integer poll = pq.poll();
      n--;
      poll--;
      if (poll != 0) {
        pq.add(poll);
      }
    }

    long answer = 0;
    while (!pq.isEmpty()) {
      Integer poll = pq.poll();
      answer += ((long) poll) * poll;
    }
    return answer;
  }
}