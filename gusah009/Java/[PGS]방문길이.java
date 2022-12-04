class Solution {

  boolean[][][] path = new boolean[11][11][4]; // U D R L
  int[][] dir = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int characterX = 5;
  int characterY = 5;

  public int solution(String dirs) {
    for (int i = 0; i < dirs.length(); i++) {
      char d = dirs.charAt(i);
      move(d);
    }
    int answer = 0;
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        for (int k = 0; k < 4; k++) {
          if (path[i][j][k]) {
            answer++;
          }
        }
      }
    }
    return answer / 2;
  }

  void move(char d) {
    if (d == 'U') {
      int nextCharacterX = characterX + dir[0][0];
      int nextCharacterY = characterY + dir[0][1];
      if (0 <= nextCharacterX && nextCharacterX < 11 &&
          0 <= nextCharacterY && nextCharacterY < 11) {
        path[characterX][characterY][0] = true;
        path[nextCharacterX][nextCharacterY][1] = true;
        characterX = nextCharacterX;
        characterY = nextCharacterY;
      }
    } else if (d == 'D') {
      int nextCharacterX = characterX + dir[1][0];
      int nextCharacterY = characterY + dir[1][1];
      if (0 <= nextCharacterX && nextCharacterX < 11 &&
          0 <= nextCharacterY && nextCharacterY < 11) {
        path[characterX][characterY][1] = true;
        path[nextCharacterX][nextCharacterY][0] = true;
        characterX = nextCharacterX;
        characterY = nextCharacterY;
      }
    } else if (d == 'R') {
      int nextCharacterX = characterX + dir[2][0];
      int nextCharacterY = characterY + dir[2][1];
      if (0 <= nextCharacterX && nextCharacterX < 11 &&
          0 <= nextCharacterY && nextCharacterY < 11) {
        path[characterX][characterY][2] = true;
        path[nextCharacterX][nextCharacterY][3] = true;
        characterX = nextCharacterX;
        characterY = nextCharacterY;
      }
    } else if (d == 'L') {
      int nextCharacterX = characterX + dir[3][0];
      int nextCharacterY = characterY + dir[3][1];
      if (0 <= nextCharacterX && nextCharacterX < 11 &&
          0 <= nextCharacterY && nextCharacterY < 11) {
        path[characterX][characterY][3] = true;
        path[nextCharacterX][nextCharacterY][2] = true;
        characterX = nextCharacterX;
        characterY = nextCharacterY;
      }
    }
  }
}public class [PGS]방문길이 {
  
}
