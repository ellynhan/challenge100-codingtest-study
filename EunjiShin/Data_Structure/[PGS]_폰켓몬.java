package DataStructure;

import java.io.IOException;
import java.util.HashMap;

public class Phoneketmon {

  public static void main(String[] args) throws IOException {
    int[] nums = new int[] { 3, 3, 3, 2, 2, 4 };
    int answer = solution(nums);
    System.out.println(answer);
  }

  public static int solution(int[] nums) {
    int answer = 0;
    HashMap<Integer, Integer> resultMap = new HashMap<>();

    for (int i = 0; i < nums.length; i++) {
      int type = nums[i];
      if (resultMap.containsKey(type)) {
        resultMap.put(type, resultMap.get(type) + 1);
      } else {
        resultMap.put(type, 1);
      }
    }

    int max = nums.length / 2;
    int size = resultMap.keySet().size();
    if (size > max) {
      answer = max;
    }else {
      answer = size;
    }

    return answer;
  }

}
