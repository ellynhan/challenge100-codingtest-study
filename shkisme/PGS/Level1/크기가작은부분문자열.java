package Level1.크기가작은부분문자열;

class Solution {

  public int solution(String t, String p) {
    int answer = 0;

    int length = p.length();
    long pValue = Long.parseLong(p);

    for (int i = 0; i < t.length(); i++) {
      if (i + length == t.length() + 1) {
        break;
      }
      long tValue = Long.parseLong(t.substring(i, i + length));
      if (tValue <= pValue) {
        answer++;
      }
    }

    return answer;
  }
}
