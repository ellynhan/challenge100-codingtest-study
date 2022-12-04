class Solution {

  public int solution(int n, int k) {
    int answer = 0;
    String s = Integer.toString(n, k);
    for (int i = 0; i < s.length(); i++) {
      StringBuilder sb = new StringBuilder();
      while (i < s.length() && s.charAt(i) != '0') {
        sb.append(s.charAt(i));
        i++;
      }
      if (sb.length() != 0 && isPrime(Long.parseLong(sb.toString()))) {
        answer++;
      }
    }
    return answer;
  }

  public boolean isPrime(long n) {
    if (n < 2) {
      return false;
    }
    for (long i = 2; i <= (long) Math.sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}