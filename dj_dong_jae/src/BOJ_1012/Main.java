package BOJ_1012;

import java.util.*;

public class Main {

    public static int t, n, m, k = 0;
    public static ArrayList<Integer> result = new ArrayList<>();
    public static int[][] map = new int[51][51];
    public static boolean[][] visited = new boolean[51][51];
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};

    public static class Node {
        int x;
        int y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            map = new int[51][51];
            visited = new boolean[51][51];
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                map[x][y] = 1;
            }
            int count = 0;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    if (map[a][b] == 1 && !visited[a][b]) {
                        Node start = new Node(a, b);
                        dfs(start);
                        count++;
                    }
                }
            }
            result.add(count);
        }

        for (int ans : result) {
            System.out.println(ans);
        }

    }

    public static void dfs(Node node) {
        visited[node.x][node.y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + node.x;
            int ny = dy[i] + node.y;
            if (nx < n && ny < m && nx >=0 && ny >=0) {
                if (map[nx][ny] == 1 && !visited[nx][ny] ) {
                    dfs(new Node(nx, ny));
                }
            }
        }
    }

}
