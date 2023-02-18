import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {


  public int solution(String str1, String str2) {
    Map<String, Integer> map1 = new HashMap<>();
    str1 = str1.toLowerCase();
    for (int i = 0; i < str1.length() - 1; i++) {
      if ('a' <= str1.charAt(i) && str1.charAt(i) <= 'z' &&
          'a' <= str1.charAt(i + 1) && str1.charAt(i + 1) <= 'z') {
        String substring = str1.substring(i, i + 2);
        if (map1.containsKey(substring)) {
          map1.put(substring, map1.get(substring) + 1);
        } else {
          map1.put(substring, 1);
        }
      }
    }
    Map<String, Integer> map2 = new HashMap<>();
    str2 = str2.toLowerCase();
    for (int i = 0; i < str2.length() - 1; i++) {
      if ('a' <= str2.charAt(i) && str2.charAt(i) <= 'z' &&
          'a' <= str2.charAt(i + 1) && str2.charAt(i + 1) <= 'z') {
        String substring = str2.substring(i, i + 2);
        if (map2.containsKey(substring)) {
          map2.put(substring, map2.get(substring) + 1);
        } else {
          map2.put(substring, 1);
        }
      }
    }

    int intersection = 0;
    for (Entry<String, Integer> entry1 : map1.entrySet()) {
      if (map2.containsKey(entry1.getKey())) {
        intersection += Math.min(entry1.getValue(), map2.get(entry1.getKey()));
      }
    }

    int union = 0;
    for (Entry<String, Integer> entry1 : map1.entrySet()) {
      if (map2.containsKey(entry1.getKey())) {
        union += Math.max(entry1.getValue(), map2.get(entry1.getKey()));
      }
    }

    for (Entry<String, Integer> entry1 : map1.entrySet()) {
      if (!map2.containsKey(entry1.getKey())) {
        union += entry1.getValue();
      }
    }

    for (Entry<String, Integer> entry2 : map2.entrySet()) {
      if (!map1.containsKey(entry2.getKey())) {
        union += entry2.getValue();
      }
    }

    if (union == 0 && intersection == 0) {
      return 65536;
    }
    return (int) ((double) intersection / union * 65536);
  }
}