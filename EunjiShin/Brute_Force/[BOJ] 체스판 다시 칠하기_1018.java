package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ChessBoard{

  static int N;
  static int M;
  static boolean[][] board;
  static int min = 64;

  public static void main(String[] args) throws IOException {
    makeBoard();

    for (int i = 0; i < N-7; i++) {
      for (int j = 0; j < M-7; j++) {
        find(i, j);
      }
    }

    System.out.println(min);
  }

  public static void makeBoard() throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    board = new boolean[N][M];

    for (int i = 0; i < N; i++) {
      String str = br.readLine();
      for (int j = 0; j < M; j++) {
        board[i][j] = str.charAt(j) == 'B';
      }
    }
  }

  public static void find(int x, int y) {
    int count = 0;
    int width = x + 8;
    int height = y + 8;
    boolean color = board[x][y];

    for (int i = x; i < width; i++) {
      for (int j = y; j < height; j++) {
        if (board[i][j] != color) {
          count++;
        }
        color = !color; // 다음 칸 색 반전
      }
      color = !color;   // 다음 줄 색 반전
    }
    count = Math.min(count, 64 - count); // 칠할 때, 첫 번째 칸부터 반대 색으로 칠할 수 있으므로 반대 케이스의 count도 구한다.
    min = Math.min(count, min);
  }

}
