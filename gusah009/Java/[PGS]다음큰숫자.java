class Solution {

  public int solution(int n) {
    int nCount = getCount(n);
    for (int i = n + 1; i < 1_000_001; i++) {
      if (getCount(i) == nCount) {
        return i;
      }
    }
    return -1;
  }

  private static int getCount(int tmp) {
    int count = 0;
    while (tmp != 0) {
      if (tmp % 2 == 1) {
        count++;
      }
      tmp /= 2;
    }
    return count;
  }
}