package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MeetRoom {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int N = Integer.parseInt(br.readLine());
    int[][] array = new int[N][2];

    // DESCRIBE: 제일 첫번째 인덱스는 자동으로 선택되니까 1부터 카운트 시작
    int result = 1;

    // DESCRIBE: 회의 시간 입력 받기
    for(int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine(), " ");
      array[i][0] = Integer.parseInt(st.nextToken());
      array[i][1] = Integer.parseInt(st.nextToken());
    }

    // DESCRIBE: 종료 시간 기준으로 오름차순 정렬
    Arrays.sort(array, (o1, o2) -> {
      if(o1[1] == o2[1]) {
        return o1[0] - o2[0];
      }else {
        return o1[1] - o2[1];
      }
    });

    // DESCRIBE: 현재 인덱스의 시작 시간이 이전 인덱스의 종료 시간보다 크거나 같다면 카운트
    int prevEndTime = array[0][1];
    for (int i = 1; i < N; i++) {
      if (array[i][0] >= prevEndTime) {
        result += 1;
        prevEndTime = array[i][1];
      }
    }

    System.out.println(result);

  }

}
