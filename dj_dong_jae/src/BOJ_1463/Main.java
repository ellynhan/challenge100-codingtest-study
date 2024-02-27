package BOJ_1463;

import java.util.*;

public class Main {

    public static int[] d = new int[1000001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 2; i <= n; i++) {
            d[i] = d[i-1] + 1;
            if (i % 3 == 0) {
                d[i] = Math.min(d[i], d[i/3] + 1);
            }
            if (i % 2 == 0) {
                d[i] = Math.min(d[i], d[i/2] + 1);
            }
        }

        System.out.println(d[n]);
    }

}
