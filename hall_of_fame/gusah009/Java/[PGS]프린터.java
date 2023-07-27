import java.util.*;

class Solution {

  int[] maxPriority = new int[10];

  public int solution(int[] priorities, int location) {
    Queue<Node> queue = new ArrayDeque<>();
    for (int i = 0; i < priorities.length; i++) {
      queue.add(new Node(priorities[i], i));
      maxPriority[priorities[i]]++;
    }

    int answer = 1;
    while (!queue.isEmpty()) {
      Node node = queue.poll();
      boolean nodeFlag = false;
      for (int i = node.priority + 1; i < 10; i++) {
        if (maxPriority[i] > 0) {
          nodeFlag = true;
          break;
        }
      }
      if (nodeFlag) {
        queue.add(node);
      } else {
        if (node.location == location) {
          break;
        }
        answer++;
        maxPriority[node.priority]--;
      }
    }
    return answer;
  }

  static class Node {

    int priority;
    int location;

    public Node(int priority, int location) {
      this.priority = priority;
      this.location = location;
    }
  }
}