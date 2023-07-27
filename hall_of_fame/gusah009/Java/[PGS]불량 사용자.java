import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

  Set<String> set = new HashSet<>();
  int answer = 0;

  public int solution(String[] user_id, String[] banned_id) {
    Data[] user_ids = Arrays.stream(user_id).map(i -> new Data(false, i)).toArray(Data[]::new);
    Data[] banned_ids = Arrays.stream(banned_id).map(i -> new Data(false, i)).toArray(Data[]::new);

    dfs(user_ids, banned_ids, 0, 0);
    return set.size();
  }

  private void dfs(Data[] user_ids, Data[] banned_ids, int userIndex, int depth) {
    if (depth == banned_ids.length) {
      set.add(String.join("",
          Arrays.stream(user_ids).filter(i -> i.isUsed).map(i -> i.name).toArray(String[]::new)));
      return;
    }

    for (int i = userIndex; i < banned_ids.length; i++) {
      for (int j = 0; j < user_ids.length; j++) {
        if (!banned_ids[i].isUsed && !user_ids[j].isUsed &&
            banned_ids[i].name.length() == user_ids[j].name.length()) {
          boolean isSame = true;
          for (int k = 0; k < user_ids[j].name.length(); k++) {
            if (banned_ids[i].name.charAt(k) == '*') {
              continue;
            }
            if (banned_ids[i].name.charAt(k) != user_ids[j].name.charAt(k)) {
              isSame = false;
              break;
            }
          }
          if (isSame) {
            banned_ids[i].isUsed = true;
            user_ids[j].isUsed = true;
            dfs(user_ids, banned_ids, i + 1, depth + 1);
            banned_ids[i].isUsed = false;
            user_ids[j].isUsed = false;
          }
        }
      }
    }
  }

  static class Data {

    boolean isUsed;
    String name;

    public Data(boolean isUsed, String name) {
      this.isUsed = isUsed;
      this.name = name;
    }
  }
}