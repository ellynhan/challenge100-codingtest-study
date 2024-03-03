package BOJ_1697;

import java.util.*;

public class Main {

    public static int n, k = 0;
    public static ArrayList<Integer> map = new ArrayList<>();
    public static class Node {
        int x;
        int count;
        Node(int x, int count) {
            this.x = x;
            this.count = count;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        int size = Math.max(n, k) * 2 + 1;
        for (int i = 0; i < size; i++) {
            map.add(-1);
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(n, 0));
        map.set(n, 0);
        while(!q.isEmpty()) {
            Node now = q.poll();
            int dx1 = now.x + 1;
            int dx2 = now.x - 1;
            int dx3 = now.x * 2;
            int[] dx = {dx1, dx2, dx3};
            for (int i = 0; i < 3; i++) {
                int nx = dx[i];
                if (nx < size && nx >= 0) {
                    if (map.get(nx) == -1) {
                        Node next = new Node(nx, now.count + 1);
                        q.offer(next);
                        map.set(next.x, next.count);
                    }
                }
            }
        }
        System.out.println(map.get(k));

    }

}
