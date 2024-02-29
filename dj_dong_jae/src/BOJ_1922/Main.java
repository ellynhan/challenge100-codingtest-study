package BOJ_1922;

import java.util.*;

class Edge implements Comparable<Edge> {
    private final int distance;
    private final int nodeA;
    private final int nodeB;
    public int getDistance() {
        return this.distance;
    }
    public int getNodeA() {
        return this.nodeA;
    }
    public int getNodeB() {
        return this.nodeB;
    }
    public Edge(int distance, int nodeA, int nodeB) {
        this.distance = distance;
        this.nodeA = nodeA;
        this.nodeB = nodeB;
    }
    @Override
    public int compareTo(Edge other) {
        if (this.distance < other.distance) {
            return -1;
        } else {
            return 1;
        }
    }
}

public class Main {

    public static int n, m;
    public static ArrayList<Edge> edges = new ArrayList<>();
    public static int[] parent = new int[1001];
    public static int result = 0;
    public static int findParent(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = findParent(parent[x]);
    }
    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            edges.add(new Edge(c, a, b));
        }

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        Collections.sort(edges);

        for (int i = 0; i < edges.size(); i++) {
            if (findParent(edges.get(i).getNodeA()) != findParent(edges.get(i).getNodeB())) {
                unionParent(edges.get(i).getNodeA(), edges.get(i).getNodeB());
                result += edges.get(i).getDistance();
            }
        }

        System.out.println(result);
    }
}
