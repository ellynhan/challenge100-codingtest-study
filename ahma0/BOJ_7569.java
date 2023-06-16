import java.io.*;
import java.util.*;

public class Main {
    static int M, N, H;
    static int[][][] arr;
    static int[] move_X = {1, -1, 0, 0, 0, 0};
    static int[] move_Y = {0, 0, -1, 1, 0, 0};
    static int[] move_Z = {0, 0, 0, 0, -1, 1};
    static int day = 0;
    static Queue<Tomato> tomatoes = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        arr = new int[H][N][M];

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for(int k = 0; k < M; k++) {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());

                    if (arr[i][j][k] == 1)
                        tomatoes.add(new Tomato(j, k, i, 0));
                }
            }
        }

        bfs();

        for(int[][] i : arr)
            for(int[] j : i)
                for(int k : j)
                    if(k == 0) {
                        System.out.println(-1);
                        return;
                    }

        System.out.println(day - 1);
    }

    public static void bfs() {
        while(!tomatoes.isEmpty()) {
            Tomato tomato = tomatoes.poll();
            int now_X = tomato.x;
            int now_Y = tomato.y;
            int now_Z = tomato.z;
            int days = tomato.day + 1;

            for(int i = 0; i < 6; i++) {
                int new_X = now_X + move_X[i];
                int new_Y = now_Y + move_Y[i];
                int new_Z = now_Z + move_Z[i];

                if(new_X < 0 || new_Y < 0 || new_Z < 0 || new_X >= N || new_Y >= M || new_Z >= H)
                    continue;

                day = days;
                if (arr[new_Z][new_X][new_Y] == 0) {
                    tomatoes.add(new Tomato(new_X, new_Y, new_Z, days));
                    arr[new_Z][new_X][new_Y] = 1;
                }

            }
        }
    }

    public static class Tomato {
        int x;
        int y;
        int z;
        int day;

        Tomato(int x, int y, int z, int day) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.day = day;
        }
    }

}