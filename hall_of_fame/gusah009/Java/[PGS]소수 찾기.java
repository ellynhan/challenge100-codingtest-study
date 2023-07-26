import java.util.HashSet;
import java.util.Set;

class Solution {

  Set<Integer> answer = new HashSet<>();

  public int solution(String numbers) {
    Number[] myNumbers = new Number[numbers.length()];
    for (int i = 0; i < numbers.length(); i++) {
      myNumbers[i] = new Number(numbers.charAt(i), false);
    }

    dfs(myNumbers, 0, "");

    return answer.size();
  }

  private void dfs(Number[] myNumbers, int index, String finalNumber) {
    if (!finalNumber.isEmpty() && isPrime(Integer.parseInt(finalNumber))) {
      answer.add(Integer.parseInt(finalNumber));
    }

    if (index == myNumbers.length) {
      return;
    }

    for (Number myNumber : myNumbers) {
      if (!myNumber.isUsed) {
        myNumber.isUsed = true;
        dfs(myNumbers, index + 1, finalNumber + myNumber.num);
        myNumber.isUsed = false;
      }
    }
  }

  private boolean isPrime(int n) {
    return (new java.math.BigInteger(String.valueOf(n))).isProbablePrime(100);
  }

  static class Number {

    char num;
    boolean isUsed;

    public Number(char num, boolean isUsed) {
      this.num = num;
      this.isUsed = isUsed;
    }
  }
}