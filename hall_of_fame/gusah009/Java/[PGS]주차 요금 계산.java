import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

class Solution {

  public int[] solution(int[] fees, String[] records) {
    Map<String, Integer> answer = new TreeMap<>();
    Map<String, Integer> cars = new HashMap<>();
    Map<String, Integer> pay = new HashMap<>();
    for (String record : records) {
      String[] split = record.split(" ");
      String[] time = split[0].split(":");
      int minute = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
      if (split[2].equals("IN")) {
        cars.put(split[1], minute);
      } else {
        int stayMin = minute - cars.get(split[1]);
        if (pay.containsKey(split[1])) {
          pay.put(split[1], pay.get(split[1]) + stayMin);
        } else {
          pay.put(split[1], stayMin);
        }
        cars.remove(split[1]);
      }
    }

    for (Entry<String, Integer> entry : cars.entrySet()) {
      int minute = 23 * 60 + 59;
      int stayMin = minute - entry.getValue();
      if (pay.containsKey(entry.getKey())) {
        pay.put(entry.getKey(), pay.get(entry.getKey()) + stayMin);
      } else {
        pay.put(entry.getKey(), stayMin);
      }
    }

    int defaultMin = fees[0];
    int defaultPay = fees[1];
    int unitMin = fees[2];
    int unitPay = fees[3];

    for (Entry<String, Integer> entry : pay.entrySet()) {
      if (entry.getValue() >= defaultMin) {
        if ((entry.getValue() - defaultMin) % unitMin == 0) {
          answer.put(entry.getKey(),
              defaultPay + (entry.getValue() - defaultMin) / unitMin * unitPay);
        } else {
          answer.put(entry.getKey(),
              defaultPay + ((entry.getValue() - defaultMin) / unitMin + 1) * unitPay);
        }
      } else {
        answer.put(entry.getKey(), defaultPay);
      }
    }
    return answer.values()
        .stream()
        .mapToInt(Integer::intValue)
        .toArray();
  }
}