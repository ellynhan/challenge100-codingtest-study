package BOJ_2667;

import java.util.*;

public class Main {

    public static int n = 0;
    public static ArrayList<Integer> result = new ArrayList<>();
    public static int[][] map = new int[26][26];
    public static boolean[][] visited = new boolean[26][26];
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

        n = sc.nextInt();

        sc.nextLine(); // 개행 문자 제거

        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < n; j++) {
                int x = str.charAt(j) - '0';
                map[i][j] = x;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    Queue<Node> q = new LinkedList<>();
                    q.offer(new Node(i, j));
                    visited[i][j] = true;
                    count++;
                    while (!q.isEmpty()) {
                        Node now = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = dx[k] + now.x;
                            int ny = dy[k] + now.y;
                            if (nx < n && ny < n && nx >= 0 && ny >= 0) {
                                if (map[nx][ny] == 1 && !visited[nx][ny]) {
                                    Node next = new Node(nx, ny);
                                    q.offer(next);
                                    visited[nx][ny] = true;
                                    count++;
                                }
                            }
                        }
                    }
                    result.add(count);
                }
            }
        }

        Collections.sort(result);
        System.out.println(result.size());
        for (Integer ans : result) {
            System.out.println(ans);
        }

    }
}
