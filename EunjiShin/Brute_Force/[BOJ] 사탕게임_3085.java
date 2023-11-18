package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CandyGame {

  static char[][] board;
  static int N;
  static int max_candy = 1;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    board = new char[N][N];

    for(int i = 0; i < N; i++) {
      String str = br.readLine();
      for (int j = 0; j < board[i].length; j++) {
        board[i][j] = str.charAt(j);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (j+1 < N) {
          swap(i, j, i, j+1);
          searchRow();
          searchCol();
          swap(i, j+1, i, j);
        }
        if (i+1 < N) {
          swap(i, j, i+1, j);
          searchRow();
          searchCol();
          swap(i+1, j, i, j);
        }
      }
    }

    System.out.println(max_candy);
  }

  public static void swap(int x1, int y1, int x2, int y2) {
    char tmp = board[x1][y1];
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = tmp;
  }

  public static void searchRow() {
    for (int i = 0; i < N; i++) {
      int cnt = 1;
      for (int j = 0; j < N-1; j++) {
        if (board[i][j] != board[i][j+1]) {
          cnt = 1;
        } else {
          cnt++;
          max_candy = Math.max(max_candy, cnt);
        }
      }
    }
  }

  public static void searchCol() {
    for (int i = 0; i < N; i++) {
      int cnt = 1;
      for (int j = 0; j < N-1; j++) {
        if (board[j][i] != board[j+1][i]) {
          cnt = 1;
        } else {
          cnt++;
          max_candy = Math.max(max_candy, cnt);
        }
      }
    }
  }

}
