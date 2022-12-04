package DataStructure;

import java.util.HashMap;
import java.util.HashSet;

public class ReportResult {

  public static void main(String[] args) {
    String[] id_list = new String[] { "muzi", "frodo", "apeach", "neo" };
    String[] report = new String[] { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;
    int[] answer = solution(id_list, report, k);
    for (int i = 0; i < answer.length; i++) {
      System.out.println(answer[i]);
    }
    return;
  }

    public static int[] solution(String[] id_list, String[] report, int k) {
      int[] answer = new int[id_list.length];

      HashMap<String, HashSet<String>> reportedMap = new HashMap<>();
      HashMap<String, Integer> resultMap = new HashMap<>();

      for(int i = 0; i < report.length; i++) {
        String reporter = report[i].split(" ")[0];
        String reported = report[i].split(" ")[1];

        if (reportedMap.containsKey(reporter)) {
          if (reportedMap.get(reporter).contains(reported)) continue;
          else {
            reportedMap.get(reporter).add(reported);
          }
        } else {
          reportedMap.put(reporter, new HashSet<String>() {{
            add(reported);
          }});
        }

        if (resultMap.containsKey(reported)) {
          resultMap.put(reported, resultMap.get(reported) + 1);
        } else {
          resultMap.put(reported, 1);
        }
      }

      for (String reported : resultMap.keySet()) {
        int cnt = resultMap.get(reported);
        if (cnt >= k) {
          for (int i = 0; i < id_list.length; i++) {
            if (reportedMap.containsKey(id_list[i]) && reportedMap.get(id_list[i]).contains(reported))
              answer[i]++;
          }
        }
      }
      return answer;
    }
  }

