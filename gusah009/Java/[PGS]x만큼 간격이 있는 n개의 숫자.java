import java.util.stream.LongStream;

class Solution {

  public long[] solution(int x, int n) {
    return LongStream.range(0, n).map(i -> (i + 1) * x).toArray();
  }
}