import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  private static final int VIRUS = 2;
  private static final int WALL = 1;
  private static final int EMPTY = 0;

  private static final int MAX = 8;
  private static final int WALL_COUNT = 3;
  private static final int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  static int[][] originBoard = new int[MAX][MAX];
  static int[][] copyBoard = new int[MAX][MAX];
  static boolean[][] visited = new boolean[MAX][MAX];
  static int[] selectedWalls = new int[WALL_COUNT];
  static int N, M, answer = 0;

  public static void main(String[] args) throws IOException {
    input();
    selectWalls(0, N * M, WALL_COUNT);
    print();
  }

  private static void selectWalls(int start, int n, int r) {
    if (r == 0) {
      answer = Math.max(answer, checkVirus());
    } else {
      for (int i = start; i < n; i++) {
        if (originBoard[i / M][i % M] == EMPTY) {
          selectedWalls[r - 1] = i;
          selectWalls(i + 1, n, r - 1);
        }
      }
    }
  }

  private static int checkVirus() {
    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        copyBoard[n][m] = originBoard[n][m];
      }
    }
    for (int selectedWall : selectedWalls) {
      copyBoard[selectedWall / M][selectedWall % M] = WALL;
    }
    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        if (copyBoard[n][m] == VIRUS) {
          spreadVirus(n, m);
        }
      }
    }

    int safeSector = 0;
    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        if (copyBoard[n][m] == EMPTY) {
          safeSector++;
        }
      }
    }
    return safeSector;
  }

  private static void spreadVirus(int n, int m) {
    for (int[] d : dir) {
      int nextN = n + d[0];
      int nextM = m + d[1];
      if (0 <= nextN && nextN < N &&
          0 <= nextM && nextM < M &&
          copyBoard[nextN][nextM] == EMPTY) {
        copyBoard[nextN][nextM] = VIRUS;
        spreadVirus(nextN, nextM);
      }
    }
  }

  private static void print() throws IOException {
    try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
      bw.write(answer + "\n");
      bw.flush();
    }
  }

  private static void input() throws IOException {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String[] NM = br.readLine().split(" ");
      N = Integer.parseInt(NM[0]);
      M = Integer.parseInt(NM[1]);
      for (int n = 0; n < N; n++) {
        String[] inputStrArr = br.readLine().split(" ");
        for (int m = 0; m < M; m++) {
          originBoard[n][m] = inputStrArr[m].charAt(0) - '0';
        }
      }
    }
  }
}