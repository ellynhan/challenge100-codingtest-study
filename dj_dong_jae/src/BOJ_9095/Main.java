package BOJ_9095;

import java.util.*;

public class Main {

    public static int[] d = new int[11];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        d[1] = 1;
        d[2] = 2;
        d[3] = 4;

        for (int i = 4; i < 11; i++) {
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }

        int t = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            list.add(sc.nextInt());
        }

        for (int n : list) {
            System.out.println(d[n]);
        }

    }

}
