import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

public class ParkFees {

  public static void main(String[] args) throws IOException {
    int[] fees = {1, 461, 1, 10};
    String[] records = {
        "00:00 1234 IN"
    };
    int[] answer = solution(fees, records);
    for (int i = 0; i < answer.length; i++) {
      System.out.println(answer[i]);
    }
  }

  public static int[] solution(int[] fees, String[] records) {
    // DESCRIBE: record에서 각 차량별 기록 분리
    LinkedHashMap<Integer, ArrayList<String>> carRecordMap = new LinkedHashMap<>();
    for (String record : records) {
      String[] recordInfo = record.split(" ");
      Integer carNumber = Integer.parseInt(recordInfo[1]);
      carRecordMap.computeIfAbsent(carNumber, k -> new ArrayList<String>()).add(recordInfo[0]);
    }

    int[] answer = new int[carRecordMap.size()];

    HashMap<Integer, Integer> carFeeMap = new HashMap<>();
    for (Entry<Integer, ArrayList<String>> entry : carRecordMap.entrySet()) {
      // DESCRIBE: records가 시간순이니까 바로 뽑아내도 됨
      ArrayList<String> recordInfo = entry.getValue();
      // DESCRIBE: 기록 수가 짝수면 입출차 쌍이 맞는거고, 홀수면 마지막 기록은 23:59에 출차한거임
      int fee = calculateFee(fees, recordInfo);
      carFeeMap.put(entry.getKey(), fee);
    }

    // DESCRIBE: 차량 번호 작은 순으로 정렬해야 함 (오름차순)
    int i = 0;
    Map<Integer, Integer> sortedMap = new TreeMap<>(carFeeMap);
    for (Integer car : sortedMap.keySet()) {
      answer[i] = sortedMap.get(car);
      i++;
    }
    return answer;
  }

  public static int calculateFee(int[] fees, ArrayList<String> records) {
    int fee = 0;
    int timeDiff = 0;

    if (records.size() % 2 != 0) {
      records.add("23:59");
    }

    for (int i = 0; i < records.size(); i+=2) {
      String inputTime = records.get(i);
      String outputTime = records.get(i+1);
      timeDiff += getTimeDifference(inputTime, outputTime);
    }

    if (timeDiff > fees[0]) {
      fee += fees[1] + (int) Math.ceil((double)(timeDiff - fees[0]) / fees[2]) * fees[3];
    } else {
      fee += fees[1];
    }

    return fee;
  }

  public static int getTimeDifference(String inputTime, String outputTime) {
    String[] input = inputTime.split(":");
    String[] output = outputTime.split(":");

    int startMinute = Integer.parseInt(input[0].trim()) * 60 + Integer.parseInt(input[1].trim());
    int endMinute = Integer.parseInt(output[0].trim()) * 60 + Integer.parseInt(output[1].trim());

    return endMinute - startMinute;
  }

}
