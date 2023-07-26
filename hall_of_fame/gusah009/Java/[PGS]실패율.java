import java.util.Arrays;

class Solution {

  public int[] solution(int N, int[] stages) {
    Fail[] failRate = new Fail[N];
    Arrays.sort(stages);
    for (int i = 0, j = 1; j <= N; j++) {
      failRate[j - 1] = new Fail();
      while (i < stages.length && stages[i] < j) {
        i++;
      }
      int total = stages.length - i;
      int count = 0;
      while (i < stages.length && stages[i] <= j) {
        i++;
        count++;
      }
      failRate[j - 1].index = j;
      if (total == 0) {
        failRate[j - 1].rate = 0;
        continue;
      }
      failRate[j - 1].rate = (double) count / total;
    }
    Arrays.sort(failRate);
    return Arrays.stream(failRate).mapToInt(o -> o.index).toArray();
  }

  static class Fail implements Comparable<Fail> {

    @Override
    public String toString() {
      return "Fail{" +
          "rate=" + rate +
          ", index=" + index +
          '}';
    }

    double rate;
    int index;

    @Override
    public int compareTo(Fail o) {

      if (this.rate == o.rate) {
        return this.index - o.index;
      }
      return Double.compare(o.rate, this.rate);
    }
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] solution1 = solution.solution(8, new int[]{1, 2, 3, 4, 5, 6, 7});
    System.out.println(Arrays.toString(solution1));
  }
}

// 2, 1, 2, 6, 2, 4, 3, 3
// 1, 2, 2, 2, 3, 3, 4, 6