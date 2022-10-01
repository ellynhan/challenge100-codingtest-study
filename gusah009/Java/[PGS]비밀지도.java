import java.util.Arrays;

class Solution {

  public String[] solution(int n, int[] arr1, int[] arr2) {
    StringBuilder[] answer = new StringBuilder[n];
    for (int i = 0; i < n; i++) {
      answer[i] = new StringBuilder();
      String s1 = Integer.toBinaryString(arr1[i]);
      String s2 = Integer.toBinaryString(arr2[i]);
      s1 = "0".repeat(n - s1.length()) + s1;
      s2 = "0".repeat(n - s2.length()) + s2;
      for (int j = 0; j < n; j++) {
        if (s1.charAt(j) == '1' || s2.charAt(j) == '1') {
          answer[i].append('#');
        } else {
          answer[i].append(' ');
        }
      }
    }
    return Arrays.stream(answer).map(StringBuilder::toString).toArray(String[]::new);
  }
}