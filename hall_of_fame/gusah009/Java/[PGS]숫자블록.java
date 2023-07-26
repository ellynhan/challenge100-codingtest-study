import java.util.ArrayList;
import java.util.List;

class Solution {

  public int[] solution(long begin, long end) {
    List<Integer> answer = new ArrayList<>((int) (end - begin + 1));
    for (long i = begin; i <= end; i++) {
      answer.add(getDivisor(i));
    }
    return answer.stream().mapToInt(i -> i).toArray();
  }

  int getDivisor(long n) {
    if (n == 1) {
      return 0;
    }
    for (int i = 2; i <= (int) Math.sqrt(n); i++) {
      if (n % i == 0) {
        if (n / i <= 10_000_000) {
          return (int) (n / i);
        }
      }
    }
    return 1;
  }
}