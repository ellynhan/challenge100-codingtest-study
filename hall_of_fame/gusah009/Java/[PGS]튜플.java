import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {

  public int[] solution(String s) {
    int[] answer = {};
    String[] split = s.split("},\\{");
    Map<Integer, Integer> map = new HashMap<>();
    for (String elements : split) {
      elements = elements.replaceAll("\\{", "");
      elements = elements.replaceAll("}", "");
      String[] ints = elements.split(",");
      for (String anInt : ints) {
        int e = Integer.parseInt(anInt);
        if (map.containsKey(e)) {
          map.put(e, map.get(e) + 1);
        } else {
          map.put(e, 1);
        }
      }
    }
    return map.entrySet().stream()
        .sorted(Entry.<Integer, Integer>comparingByValue().reversed())
        .mapToInt(Entry::getKey).toArray();
  }
}