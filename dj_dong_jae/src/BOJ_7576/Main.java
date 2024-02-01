package BOJ_7576;

import java.util.*;

public class Main {

    public static int n, m = 0;
    public static int[][] map = new int[1001][1001];
    public static boolean[][] visited = new boolean[1001][1001];
    public static ArrayList<Node> rottenTomatoes = new ArrayList<>();
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};
    public static class Node {
        int x;
        int y;
        int stage;
        Node(int x, int y, int stage) {
            this.x = x;
            this.y = y;
            this.stage = stage;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        m = sc.nextInt();
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = sc.nextInt();
                map[i][j] = x;
                if (x == 1) rottenTomatoes.add(new Node(i, j, 0));
            }
        }

        Queue<Node> q = new LinkedList<>();
        for (Node tomato : rottenTomatoes) {
            q.offer(tomato);
            visited[tomato.x][tomato.y] = true;
        }
        int result = 0;
        while (!q.isEmpty()) {
            Node now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + now.x;
                int ny = dy[i] + now.y;
                if (nx < n && ny < m && nx >= 0 && ny >= 0) {
                    if (map[nx][ny] == 0 && !visited[nx][ny]) {
                        int stage = now.stage + 1;
                        result = Math.max(result, stage);
                        visited[nx][ny] = true;
                        map[nx][ny] = 1;
                        q.offer(new Node(nx, ny, stage));
                    }
                }
            }
        }

        boolean flag = true;
        outerLoop:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    flag = false;
                    break outerLoop;
                }
            }
        }

        if (flag) {
            System.out.println(result);
        } else {
            System.out.println("-1");
        }

    }

}
