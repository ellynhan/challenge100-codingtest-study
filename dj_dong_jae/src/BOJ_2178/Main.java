package BOJ_2178;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static int n, m, result = 0;
    public static int[][] map = new int[101][101];
    public static boolean[][] visited = new boolean[101][101];
    public static int[][] distance = new int[101][101];

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        sc.nextLine(); // 개행 문자 제거

        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < m; j++) {
                int now = str.charAt(j) - '0';
                map[i+1][j+1] = now;
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(1, 1));
        visited[1][1] = true;
        distance[1][1] = 1;
        while(!q.isEmpty()) {
            Node now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + now.x;
                int ny = dy[i] + now.y;
                if (nx <= n && ny <= m && nx > 0 && ny > 0) {
                    if (!visited[nx][ny] && map[nx][ny] == 1) {
                        Node next = new Node(nx, ny);
                        q.offer(next);
                        visited[nx][ny] = true;
                        distance[nx][ny] = distance[now.x][now.y] + 1;
                    }
                }
            }
        }

        System.out.println(distance[n][m]);

    }

    public static class Node {
        public int x;
        public int y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}

