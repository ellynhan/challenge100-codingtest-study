import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class Solution {

  public int[] solution(int[] progresses, int[] speeds) {
    List<Integer> answer = new ArrayList<>();
    Queue<Integer> queue = new ArrayDeque<>();

    for (int i = 0; i < progresses.length; i++) {
      queue.add((int) Math.ceil((100 - progresses[i]) / (double) speeds[i]));
    }

    int releaseFeatureCount = 0;
    int releaseFeatureDay = 0;
    while (!queue.isEmpty()) {
      releaseFeatureDay = queue.poll();
      releaseFeatureCount++;

      while (!queue.isEmpty()) {
        int featureFinishDay = queue.peek();
        if (featureFinishDay <= releaseFeatureDay) {
          queue.poll();
          releaseFeatureCount++;
        } else {
          break;
        }
      }

      answer.add(releaseFeatureCount);

      releaseFeatureCount = 0;
      releaseFeatureDay = 0;
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}