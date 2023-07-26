class Solution {

  public String solution(String s) {
    String answer = "";
    String[] s1 = s.split(" ");
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;

    for (String sNum : s1) {
      int num = Integer.parseInt(sNum);
      max = Math.max(num, max);
      min = Math.min(num, min);
    }
    return min + " " + max;
  }
}