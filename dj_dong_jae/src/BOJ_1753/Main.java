package BOJ_1753;

import java.util.*;

class Node implements Comparable<Node> {
    int index;
    int distance;
    Node(int index, int distance) {
        this.index = index;
        this.distance = distance;
    }

    @Override
    public int compareTo(Node other) {
        if (this.distance < other.distance) {
            return -1;
        } else {
            return 1;
        }
    }
}

public class Main {

    public static final int INF = 987654321;
    public static int n, e, k;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<>();
    public static int[] d = new int[20001];
    public static boolean[] visited = new boolean[20001];

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        d[start] = 0;
        while (!pq.isEmpty()) {
            Node now = pq.poll();
            int index = now.index;
            if (!visited[index]) {
                for (int i = 0; i < graph.get(index).size(); i++) {
                    Node next = graph.get(index).get(i);
                    int cost = d[index] + next.distance;
                    if (d[next.index] > cost) {
                        d[next.index] = cost;
                        pq.offer(new Node(next.index, cost));
                    }
                }
                visited[index] = true;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        e = sc.nextInt();
        k = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            d[i] = INF;
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            graph.get(u).add(new Node(v, w));
        }

        dijkstra(k);

        for (int i = 1; i <= n; i++) {
            if (d[i] == INF) {
                System.out.println("INF");
            } else {
                System.out.println(d[i]);
            }
        }
    }

}
