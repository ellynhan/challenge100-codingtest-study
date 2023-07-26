import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {

  Map<String, Integer> map = new LinkedHashMap<>();

  public String solution(String[] survey, int[] choices) {
    for (int i = 0; i < choices.length; i++) {
      choices[i] -= 4;
    }
    map.put("RT", 0);
    map.put("CF", 0);
    map.put("JM", 0);
    map.put("AN", 0);
    for (int i = 0; i < survey.length; i++) {
      if (map.containsKey(survey[i])) {
        map.put(survey[i], map.get(survey[i]) + choices[i]);
      } else {
        String s = String.valueOf(survey[i].charAt(1)) + survey[i].charAt(0);
        map.put(s, map.get(s) - choices[i]);
      }
    }
    StringBuilder answer = new StringBuilder();
    for (Entry<String, Integer> entry : map.entrySet()) {
      if (entry.getValue() > 0) {
        answer.append(entry.getKey().charAt(1));
      } else {
        answer.append(entry.getKey().charAt(0));
      }
    }
    return answer.toString();
  }
}