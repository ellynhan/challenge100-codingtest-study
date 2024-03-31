package BOJ_11021;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            sb.append("Case #").append(i).append(": ").append(a+b).append("\n");
        }
        System.out.println(sb);
    }
}