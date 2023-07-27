package acmicpc.hyeonmo.programmers.모의고사;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

  final static int STUDENT_NUM = 3;

  public int[] solution(int[] answers) {
    List<Integer> answer = new ArrayList<>();

    int[] studentsScore = new int[STUDENT_NUM];
    int[] studentAnswerPattern1 = new int[]{1, 2, 3, 4, 5};
    int[] studentAnswerPattern2 = new int[]{2, 1, 2, 3, 2, 4, 2, 5};
    int[] studentAnswerPattern3 = new int[]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int myIndex1 = 0, myIndex2 = 0, myIndex3 = 0;
    for (int ans : answers) {
      if (ans == studentAnswerPattern1[myIndex1]) {
        studentsScore[0]++;
      }
      myIndex1 = (myIndex1 + 1) % studentAnswerPattern1.length;

      if (ans == studentAnswerPattern2[myIndex2]) {
        studentsScore[1]++;
      }
      myIndex2 = (myIndex2 + 1) % studentAnswerPattern2.length;

      if (ans == studentAnswerPattern3[myIndex3]) {
        studentsScore[2]++;
      }
      myIndex3 = (myIndex3 + 1) % studentAnswerPattern3.length;
    }

    int max = Arrays.stream(studentsScore).max().getAsInt();
    for (int i = 0; i < STUDENT_NUM; i++) {
      if (studentsScore[i] == max) {
        answer.add(i + 1);
      }
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}
