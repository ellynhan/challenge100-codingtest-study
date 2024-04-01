package PGS_181944;

import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long num = Long.parseLong(st.nextToken());
        StringBuilder sb = new StringBuilder();

        sb.append(num).append(" is ");
        if (num % 2 == 0) {
            sb.append("even");
        } else {
            sb.append("odd");
        }

        System.out.println(sb);
    }
}