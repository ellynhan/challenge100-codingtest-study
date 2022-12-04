import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

  Map<String, Integer> dict = new HashMap<>();
  int maxVal = 26;

  public int[] solution(String msg) {
    List<Integer> answer = new ArrayList<>();

    init();

    for (int i = 0; i < msg.length(); ) {
      int start = i;
      while (i < msg.length() && dict.containsKey(msg.substring(start, i + 1))) {
        i++;
      }
      if (i + 1 < msg.length()) {
        dict.put(msg.substring(start, i + 1), ++maxVal);
      }
      String substring = msg.substring(start, i);
      answer.add(dict.get(substring));
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }

  private void init() {
    for (int i = 1; i <= 26; i++) {
      dict.put(String.valueOf((char) ('A' + i - 1)), i);
    }
  }

//  public static void main(String[] args) {
//    Solution solution = new Solution();
//    System.out.println(Arrays.toString(solution.solution("A")));
//  }
}
