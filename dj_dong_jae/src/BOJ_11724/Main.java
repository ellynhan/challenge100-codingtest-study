package BOJ_11724;

import java.util.*;

public class Main {
    public static int n, m, result = 0;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    public static boolean[] visited = new boolean[1001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            graph.get(x).add(y);
            graph.get(y).add(x);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                Queue<Integer> q = new LinkedList<>();
                q.offer(i);
                visited[i] = true;
                while (!q.isEmpty()) {
                    int now = q.poll();
                    for (int j = 0; j < graph.get(now).size(); j++) {
                        int next = graph.get(now).get(j);
                        if (!visited[next]) {
                            q.offer(next);
                            visited[next] = true;
                        }
                    }
                }
                result++;
            }
        }

        System.out.println(result);

    }

}
