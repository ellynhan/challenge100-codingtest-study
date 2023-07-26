class Solution {

  int N, M;

  public boolean solution(int[][] key, int[][] lock) {
    N = key.length;
    M = lock.length;
    for (int i = 0; i < 4; i++) {
      rotate(key);
      /*for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          System.out.print(key[j][k] + " ");
        }
        System.out.println();
      }*/
      for (int offsetI = -N; offsetI < M; offsetI++) {
        for (int offsetJ = -N; offsetJ < M; offsetJ++) {
          if (tryCheckLock(key, lock, offsetI, offsetJ)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  private void rotate(int[][] key) {
    for (int x = 0; x < N / 2; x++) {
      for (int y = x; y < N - x - 1; y++) {
        int temp = key[x][y];
        key[x][y] = key[y][N - 1 - x];
        key[y][N - 1 - x] = key[N - 1 - x][N - 1 - y];
        key[N - 1 - x][N - 1 - y] = key[N - 1 - y][x];
        key[N - 1 - y][x] = temp;
      }
    }
  }

  private boolean tryCheckLock(int[][] key, int[][] lock, int offsetI, int offsetJ) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        boolean lockFlag = false;
        if (offsetI <= i && offsetJ <= j) {
          if (i - offsetI < N && j - offsetJ < N &&
              key[i - offsetI][j - offsetJ] == 1) {
            if (lock[i][j] == 1) {
              return false;
            } else {
              lockFlag = true;
            }
          }
        }
        if (!lockFlag && lock[i][j] == 0) {
          return false;
        }
      }
    }
    return true;
  }
}
