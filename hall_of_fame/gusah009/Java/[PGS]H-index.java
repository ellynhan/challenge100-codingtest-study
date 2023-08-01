import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {

  public int solution(int[] citations) {

    Queue<Integer> queue = IntStream.of(citations)
        .boxed()
        .sorted(Comparator.reverseOrder())
        .collect(Collectors.toCollection(ArrayDeque::new));

    int h = 0;
    int answer;
    int maxCitation = queue.peek();
    for (answer = maxCitation; answer >= -1; answer--) {
      while (!queue.isEmpty() && queue.peek() == answer) {
        queue.poll();
        h++;
        if (h >= answer && citations.length - h <= answer) {
          break;
        }
      }
      if (h >= answer && citations.length - h <= answer) {
        break;
      }
    }

    return answer;
  }
}