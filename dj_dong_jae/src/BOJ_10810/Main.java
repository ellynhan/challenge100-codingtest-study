package BOJ_10810;
import java.util.*;
import java.io.*;

public class Main {
    public static long[] array = new long[101];
    public static long n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Long.parseLong(st.nextToken());
        m = Long.parseLong(st.nextToken());

        for (long i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            long start = Long.parseLong(st.nextToken());
            long end = Long.parseLong(st.nextToken());
            long num = Long.parseLong(st.nextToken());
            for (long j = start; j <= end; j++) {
                array[(int)j] = num;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (long i = 1; i <= n; i++) {
            sb.append(array[(int)i]).append(" ");
        }
        System.out.println(sb);
    }
}
