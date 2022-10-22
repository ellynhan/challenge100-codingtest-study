class Solution {

  public String solution(String p) {
    return recur(p);
  }

  String recur(String s) {
    if (s.isEmpty()) {
      return "";
    }
    int i = 0;
    int tmp = 0;
    do {
      tmp += s.charAt(i) == ')' ? 1 : -1;
      i++;
    } while (tmp != 0);
    String u = s.substring(0, i);
    String v = s.substring(i);

    String result;
    if (s.charAt(0) == '(') {
      result = u + recur(v);
    } else {
      result = '(' + recur(v) + ')' + getReverse(u.substring(1, i - 1));
    }

    return result;
  }

  private static String getReverse(String u) {
    u = u.replace('(', '.');
    u = u.replace(')', '(');
    u = u.replace('.', ')');
    return u;
  }
}