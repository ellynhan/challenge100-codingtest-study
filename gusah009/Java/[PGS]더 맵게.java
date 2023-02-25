import java.util.PriorityQueue;
import java.util.Queue;

class Solution {

  public int solution(int[] scoville, int K) {
    Queue<Long> pq = new PriorityQueue<>();
    for (int s : scoville) {
      pq.add((long) s);
    }

    int answer = 0;
    while (!pq.isEmpty() && pq.peek() <= K) {
      Long s1 = pq.poll();
      if (pq.isEmpty()) {
        return -1;
      }
      Long s2 = pq.poll();
      pq.add(s1 + s2 * 2);
      answer++;
    }
    if (pq.isEmpty()) {
      return -1;
    }
    return answer;
  }
}