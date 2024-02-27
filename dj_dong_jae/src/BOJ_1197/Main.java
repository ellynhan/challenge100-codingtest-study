package BOJ_1197;

import java.util.*;

class Edge implements Comparable<Edge> {
    private final int distance;
    private final int nodeA;
    private final int nodeB;

    public Edge(int distance, int nodeA, int nodeB) {
        this.distance = distance;
        this.nodeA = nodeA;
        this.nodeB = nodeB;
    }

    public int getDistance() {
        return this.distance;
    }

    public int getNodeA() {
        return this.nodeA;
    }

    public int getNodeB() {
        return this.nodeB;
    }

    @Override
    public int compareTo(Edge other) {
        if (this.getDistance() < other.getDistance()) {
            return -1;
        } else {
            return 1;
        }
    }
}

public class Main {

    public static int v, e;
    public static ArrayList<Edge> edges = new ArrayList<>();
    public static int[] parent = new int[10001];
    public static int result = 0;
    public static int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }
    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        v = sc.nextInt();
        e = sc.nextInt();

        for (int i = 1; i <= v; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < e; i++) {
            int nodeA = sc.nextInt();
            int nodeB = sc.nextInt();
            int distance = sc.nextInt();
            edges.add(new Edge(distance, nodeA, nodeB));
        }

        Collections.sort(edges);

        for (int i = 0; i < edges.size(); i++) {
            Edge now = edges.get(i);
            if (findParent(now.getNodeA()) != findParent(now.getNodeB())) {
                unionParent(now.getNodeA(), now.getNodeB());
                result += now.getDistance();
            }
        }

        System.out.println(result);

    }

}
