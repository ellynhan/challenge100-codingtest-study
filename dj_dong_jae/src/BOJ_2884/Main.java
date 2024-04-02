package BOJ_2884;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long h = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        long totalMin = h * 60 + m;
        long ansMin = totalMin - 45;
        if (ansMin < 0) {
            ansMin = 24 * 60 + ansMin;
        }
        long H = ansMin / 60;
        long M = ansMin % 60;

        StringBuilder sb = new StringBuilder();
        sb.append(H).append(" ").append(M);
        System.out.println(sb);
    }
}
