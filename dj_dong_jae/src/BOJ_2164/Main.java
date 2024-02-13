package BOJ_2164;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static int n;
    public static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            q.offer(i);
        }

        while (q.size() > 1) {
            q.poll();
            int top = q.poll();
            q.offer(top);
        }

        int result = q.peek();
        System.out.println(result);
    }

}
