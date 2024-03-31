package BOJ_2439;

import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());

        StringBuilder sb = new StringBuilder();
        for (long i = n-1; i >= 0; i--) {
            for (long j = 0; j < i; j++) {
                sb.append(" ");
            }
            for (long k = 0; k < n-i; k++) {
                sb.append("*");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
