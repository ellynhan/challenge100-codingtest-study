package PGS_181947;

import java.io.*;
import java.util.*;

public class Solution {

    public static int n, m, result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = n + m;

        StringBuilder sb = new StringBuilder();
        sb.append(n).append(" ");
        sb.append("+").append(" ");
        sb.append(m).append(" ");
        sb.append("= ").append(result).append("\n");

        System.out.println(sb);

    }
}