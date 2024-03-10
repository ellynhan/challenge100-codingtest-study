package BOJ_11726;

import java.util.*;

public class Main {

    public static long[] d = new long[1001];
    public static long result = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        d[1] = 1;
        d[2] = 2;
        for (int i = 3; i < 1001; i++) {
            d[i] = (d[i-1] + d[i-2]) % 10007L;
        }

        int n = sc.nextInt();
        result = d[n];
        System.out.println(result);
    }

}
