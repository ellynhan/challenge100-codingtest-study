import static java.lang.Math.abs;

class Solution {

  public String solution(int[] numbers, String hand) {
    StringBuilder answer = new StringBuilder();
    int left = 9, right = 11;
    for (var number : numbers) {
      if (number == 0) {
        number = 11;
      }
      number--;
      if (number == 0 || number == 3 || number == 6) {
        left = number;
        answer.append('L');
      } else if (number == 2 || number == 5 || number == 8) {
        right = number;
        answer.append('R');
      } else {
        int leftDist = left % 3 == 1 ? abs(number - left) / 3 : abs(number / 3 - left / 3) + 1;
        int rightDist = right % 3 == 1 ? abs(number - right) / 3 : abs(number / 3 - right / 3) + 1;
        System.out.println("dist = " + number + 1 + ": " + leftDist + " " + rightDist);
        if (leftDist > rightDist) {
          right = number;
          answer.append('R');
        } else if (leftDist < rightDist) {
          left = number;
          answer.append('L');
        } else {
          if (hand.equals("right")) {
            right = number;
            answer.append('R');
          } else {
            left = number;
            answer.append('L');
          }
        }
      }
    }
    return answer.toString();
  }
}
/*
 * 0 1 2
 * 3 4 5
 * 6 7 8
 *  10
 * */