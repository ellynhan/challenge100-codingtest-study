import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.PriorityQueue;

class Solution {

  PriorityQueue<Integer> pqMax = new PriorityQueue<>(Collections.reverseOrder());
  PriorityQueue<Integer> pqMin = new PriorityQueue<>();
  Map<Integer, Integer> map = new HashMap<>();

  public int[] solution(String[] operations) {
    for (String op : operations) {
      if (map.isEmpty() || pqMin.isEmpty() || pqMax.isEmpty()) {
        pqMin.clear();
        pqMax.clear();
      }
      String[] s = op.split(" ");
      int num = Integer.parseInt(s[1]);
      if (Objects.equals(s[0], "I")) {
        if (map.containsKey(num)) {
          map.put(num, map.get(num) + 1);
        } else {
          map.put(num, 1);
        }
        pqMax.add(num);
        pqMin.add(num);
      } else {
        if (num == -1) {
          while (true) {
            if (pqMin.isEmpty()) {
              break;
            }
            Integer min = pqMin.poll();
            if (map.containsKey(min)) {
              int calcNum = map.get(min) - 1;
              if (calcNum == 0) {
                map.remove(min);
              } else {
                map.put(min, calcNum);
              }
              break;
            }
          }
        } else {
          while (true) {
            if (pqMax.isEmpty()) {
              break;
            }
            Integer max = pqMax.poll();
            if (map.containsKey(max)) {
              int calcNum = map.get(max) - 1;
              if (calcNum == 0) {
                map.remove(max);
              } else {
                map.put(max, calcNum);
              }
              break;
            }
          }
        }
      }
    }
    if (map.isEmpty() || pqMin.isEmpty() || pqMax.isEmpty()) {
      return new int[]{0, 0};
    }
    return new int[]{pqMax.peek(), pqMin.peek()};
  }
}