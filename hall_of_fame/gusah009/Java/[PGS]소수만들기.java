class Solution {

  public int solution(int[] nums) {
    int answer = 0;
    for (int i = 0; i < nums.length; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        for (int k = j + 1; k < nums.length; k++) {
          if (isPrime(nums[i] + nums[j] + nums[k])) {
            answer++;
          }
        }
      }
    }
    return answer;
  }

  static boolean isPrime(int n) {
    if (n < 2) {
      return false;
    }
    for (int i = 2; i <= (int) Math.sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
