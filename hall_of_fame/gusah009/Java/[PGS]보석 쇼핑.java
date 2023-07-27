import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

  Map<String, Integer> map = new HashMap<>();

  public int[] solution(String[] gems) {
    Set<String> set = new HashSet<>(Arrays.asList(gems));
    int gemCounts = set.size();

    int[] answer = {0, 100_001};
    int cursor1 = 0;
    int cursor2 = 1;
    map.put(gems[cursor1], 1);
    while (true) {
      while (map.size() == gemCounts) {
        if (cursor1 == gems.length) {
          break;
        }
        String removeGem = gems[cursor1];
        map.put(removeGem, map.get(removeGem) - 1);
        if (map.get(removeGem) == 0) {
          map.remove(removeGem);
        }
        if (map.size() != gemCounts) {
          if (answer[1] - answer[0] > cursor2 - cursor1 - 1) {
            answer = new int[]{cursor1 + 1, cursor2};
          }
          cursor1++;
          break;
        }
        cursor1++;
      }
      if (cursor2 == gems.length) {
        break;
      }
      cursor2++;
      String addGem = gems[cursor2 - 1];
      if (map.containsKey(addGem)) {
        map.put(addGem, map.get(addGem) + 1);
      } else {
        map.put(addGem, 1);
      }
    }

    return answer;
  }
}