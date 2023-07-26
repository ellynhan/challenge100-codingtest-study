import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

  public int solution(String[] want, int[] number, String[] discount) {
    int answer = 0;
    int payCount = Arrays.stream(number).sum();
    for (int i = 0; i < discount.length - payCount + 1; i++) {
      Map<String, Integer> map = new HashMap<>();
      for (int j = 0; j < want.length; j++) {
        map.put(want[j], number[j]);
      }
      for (int j = 0; j < payCount; j++) {
        if (map.containsKey(discount[i + j])) {
          map.put(discount[i + j], map.get(discount[i + j]) - 1);
        }
      }
      if (isAllSelected(map)) {
        answer++;
      }
    }
    return answer;
  }

  private static boolean isAllSelected(Map<String, Integer> map) {
    for (Integer value : map.values()) {
      if (value != 0) {
        return false;
      }
    }
    return true;
  }
}