package PGS_181946;

import java.util.*;
import java.io.*;


public class Solution{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String str1 = st.nextToken();
        String str2 = st.nextToken();

        StringBuilder sb = new StringBuilder();
        sb.append(str1).append(str2).append("\n");

        System.out.println(sb);
    }
}
