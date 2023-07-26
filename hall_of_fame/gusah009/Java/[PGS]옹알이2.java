class Solution {

  private static final String[] words = new String[]{"aya", "ye", "woo", "ma"};
  private static final String[] blacklist = new String[]{"ayaaya", "yeye", "woowoo", "mama"};

  public int solution(String[] babbling) {
      int answer = 0;
      for (String babb : babbling) {
          if (isContainBlacklist(babb)) {
              continue;
          }
          for (String word : words) {
              babb = babb.replaceAll(word, "x".repeat(word.length()));
          }
          if (babb.equals("x".repeat(babb.length()))) {
              answer++;
          }
      }
      return answer;
  }

  private static boolean isContainBlacklist(String babb) {
      for (String blackWord : blacklist) {
          if (babb.contains(blackWord)) {
              return true;
          }
      }
      return false;
  }
}