package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class TieNum {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    List<Integer> plusArray = new ArrayList<>();
    List<Integer> minusArray = new ArrayList<>();

    int result = 0;

    // DESCRIBE: 수 입력
    for (int i = 0; i < N; i++) {
      Integer num = Integer.parseInt(br.readLine());
      if (num <= 0) minusArray.add(num);
      else plusArray.add(num);
    }

    // DESCRIBE: 양수 배열은 내림차순 정렬, 음수 배열은 오름차순 정렬
    Collections.sort(plusArray, Comparator.reverseOrder());
    Collections.sort(minusArray);

    // DESCRIBE: 수 묶기
    result += tieNum(plusArray);
    result += tieNum(minusArray);

    System.out.println(result);

  }

  public static int tieNum(List<Integer> numList) {
    int result = 0;
    int size = numList.size();
    int j = 0;
    while (j < size) {
      // DESCRIBE: 전체 크기가 짝수일 때 마지막 수가 아니라면, 그리고 현재랑 다음이 1이 아니라면 곱해서 더하기
      if (j+1 < size && numList.get(j) != 1 && numList.get(j+1) != 1) {
        result += numList.get(j++) * numList.get(j++);
      }

      // DESCRIBE: 아니라면 각각 더하기
      else {
        result += numList.get(j++);
      }
    }
    return result;
  }

}
