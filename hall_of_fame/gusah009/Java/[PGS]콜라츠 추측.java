class Solution {

  public int solution(int num) {
    long longNum = num;
    int count = 0;
    while (longNum != 1) {
      if (longNum % 2 == 0) {
        longNum /= 2;
      } else {
        longNum = longNum * 3 + 1;
      }
      count++;
      if (count == 500) {
        return -1;
      }
    }
    return count;
  }
}