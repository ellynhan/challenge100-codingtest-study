package BOJ_4386;

import java.util.*;

class Edge implements Comparable<Edge> {
    public final double distance;
    public final Node nodeA;
    public final Node nodeB;
    public Edge(Node nodeA, Node nodeB) {
        this.nodeA = nodeA;
        this.nodeB = nodeB;
        this.distance = Math.sqrt(Math.pow((nodeA.x - nodeB.x), 2) + Math.pow((nodeA.y - nodeB.y), 2));
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

class Node {
    public final int id;
    public final double x;
    public final double y;
    public Node(int id, double x, double y) {
        this.id = id;
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static int n;
    public static ArrayList<Edge> edges = new ArrayList<>();
    public static ArrayList<Node> nodes = new ArrayList<>();
    public static int[] parent = new int[101];
    public static double result = 0;
    public static int findParent(int id) {
        if (id == parent[id]) return id;
        return parent[id] = findParent(parent[id]);
    }
    public static void unionParent(int idA, int idB) {
        idA = findParent(idA);
        idB = findParent(idB);
        if (idA < idB) parent[idB] = idA;
        else parent[idA] = idB;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int count = 0;
        for (int i = 0; i < n; i++) {
            double x = sc.nextDouble();
            double y = sc.nextDouble();
            nodes.add(new Node(++count, x, y));
            parent[count] = count;
        }

        for (int i = 0; i < n; i++) {
            Node nodeA = nodes.get(i);
            for (int j = i+1; j < n; j++) {
                Node nodeB = nodes.get(j);
                edges.add(new Edge(nodeA, nodeB));
            }
        }

        Collections.sort(edges);

        for (int i = 0; i < edges.size(); i++) {
            Edge now = edges.get(i);
            Node nodeA = now.nodeA;
            Node nodeB = now.nodeB;
            if (findParent(nodeA.id) != findParent(nodeB.id)) {
                unionParent(nodeA.id, nodeB.id);
                result += now.distance;
            }
        }

        System.out.printf("%.2f", result);
    }

}
