import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

  public String[] solution(String[] record) {
    Map<String, String> map = new HashMap<>();
    for (String r : record) {
      String[] s = r.split(" ");
      String command = s[0];
      String src = s[1];
      switch (command) {
        case "Enter" -> {
          String dst = s[2];
          map.put(src, dst);
        }
        case "Leave" -> {
        }
        case "Change" -> {
          System.out.println(Arrays.toString(s));
          String dst = s[2];
          map.put(src, dst);
        }
      }
    }

    List<String> answer = new ArrayList<>();
    for (String r : record) {
      String[] s = r.split(" ");
      String command = s[0];
      String member = s[1];
      switch (command) {
        case "Enter" -> {
          answer.add(map.get(member) + "님이 들어왔습니다.");
        }
        case "Leave" -> {
          answer.add(map.get(member) + "님이 나갔습니다.");
        }
      }
    }
    return answer.toArray(String[]::new);
  }
}