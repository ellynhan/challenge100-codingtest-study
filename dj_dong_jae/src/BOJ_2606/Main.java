package BOJ_2606;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static boolean[] visited = new boolean[101];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        int count = 0;
        visited[1] = true;
        while (!q.isEmpty()) {
            int now = q.poll();
            for (int i = 0; i < graph.get(now).size(); i++) {
                int next = graph.get(now).get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    count += 1;
                    q.offer(next);
                }
            }
        }

        System.out.println(count);

    }

}
