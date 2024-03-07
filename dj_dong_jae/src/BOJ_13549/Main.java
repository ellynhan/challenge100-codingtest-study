package BOJ_13549;

import java.util.*;

class Node implements Comparable<Node> {
    public int index;
    public int time;
    public Node(int index, int time) {
        this.index = index;
        this.time = time;
    }
    public int compareTo(Node other) {
        if (this.time < other.time) {
            return -1;
        } else {
            return 1;
        }
    }
}

public class Main {

    public static final int INF = (int) 1e9;
    public static int n, k;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<>();
    public static int[] d = new int[100001];
    public static boolean[] v = new boolean[100001];

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        d[start] = 0;
        while (!pq.isEmpty()) {
            Node now = pq.poll();
            int index = now.index;
            if (!v[index]) {
                for (int i = 0; i < graph.get(index).size(); i++) {
                    Node next = graph.get(index).get(i);
                    int cost = d[index] + next.time;
                    if (cost < d[next.index]) {
                        d[next.index] = cost;
                        pq.offer(new Node(next.index, cost));
                    }
                }
                v[index] = true;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        for (int i = 0; i <= 100000; i++) {
            graph.add(new ArrayList<>());
            d[i] = INF;
        }

        for (int i = 0; i < 100000; i++) {
            graph.get(i).add(new Node(i+1, 1));
        }

        for (int i = 1; i <= 100000; i++) {
            graph.get(i).add(new Node(i-1, 1));
        }

        for (int i = 1; i <= 50000; i++) {
            graph.get(i).add(new Node(i*2, 0));
        }

        dijkstra(n);

        System.out.println(d[k]);
    }

}

