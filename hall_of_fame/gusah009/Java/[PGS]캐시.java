import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {

  Map<String, Integer> map = new HashMap<>();
  int seq = 1;

  public int solution(int cacheSize, String[] cities) {
    int answer = 0;
    for (String city : cities) {
      city = city.toLowerCase();
      if (map.containsKey(city)) {
        map.put(city, seq++);
        answer++;
      } else {
        if (cacheSize != 0) {
          if (map.size() == cacheSize) {
            Entry<String, Integer> min = Collections.min(map.entrySet(), Entry.comparingByValue());
            map.remove(min.getKey());
          }
          map.put(city, seq++);
        }
        answer += 5;
      }
    }
    return answer;
  }
}