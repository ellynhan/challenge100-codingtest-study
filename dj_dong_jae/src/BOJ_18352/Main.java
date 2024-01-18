package BOJ_18352;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();

        boolean[] visited = new boolean[n + 1];
        visited[x] = true;
        int[] distance = new int[n + 1];
        ArrayList<ArrayList<Integer>> listedGraph = new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            listedGraph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            listedGraph.get(a).add(b);
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(x);
        while (!q.isEmpty()) {
            int now = q.poll();
            for (int i = 0; i < listedGraph.get(now).size(); i++) {
                int next = listedGraph.get(now).get(i);
                if (!visited[next]) {
                    distance[next] = distance[now] + 1;
                    visited[next] = true;
                    q.offer(next);
                }
            }
        }

        boolean check = false;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == k) {
                System.out.println(i);
                check = true;
            }
        }

        if (!check) System.out.println(-1);

    }

}

