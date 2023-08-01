class Solution {

  int answer = 0;
  int k;

  public int solution(int k, int[][] dungeons) {
    this.k = k;
    permutation(dungeons, 0, dungeons.length, dungeons.length);
    return answer;
  }

  private void permutation(int[][] arr, int depth, int n, int r) {
    if (depth == r) {
      User user = new User(k);
      answer = Math.max(answer, travelDungeon(user, arr, 0, 0));
      return;
    }

    for (int i = depth; i < n; i++) {
      swap(arr, depth, i);
      permutation(arr, depth + 1, n, r);
      swap(arr, depth, i);
    }
  }

  private void swap(int[][] arr, int depth, int i) {
    int[] temp = arr[depth];
    arr[depth] = arr[i];
    arr[i] = temp;
  }

  private int travelDungeon(User user, int[][] dungeons, int currDungeonIndex,
      int selectDungeonCount) {
    if (dungeons.length == currDungeonIndex) {
      return selectDungeonCount;
    }
    int result1 = 0, result2;
    int requireMinPirodo = dungeons[currDungeonIndex][0];
    int spendPirodo = dungeons[currDungeonIndex][1];

    if (user.pirodo >= requireMinPirodo) {
      result1 = travelDungeon(new User(user.pirodo - spendPirodo),
          dungeons,
          currDungeonIndex + 1,
          selectDungeonCount + 1);
    }
    result2 = travelDungeon(new User(user.pirodo),
        dungeons,
        currDungeonIndex + 1,
        selectDungeonCount);
    return Math.max(result1, result2);
  }

  class User {

    int pirodo;

    public User(int pirodo) {
      this.pirodo = pirodo;
    }
  }
}