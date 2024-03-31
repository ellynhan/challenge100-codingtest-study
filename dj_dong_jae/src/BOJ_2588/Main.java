package BOJ_2588;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        String str = st.nextToken();

        int blank3 = x * (str.charAt(2) - '0');
        int blank4 = x * (str.charAt(1) - '0');
        int blank5 = x * (str.charAt(0) - '0');

        int blank6 = x * Integer.parseInt(str);

        StringBuilder sb = new StringBuilder();
        sb.append(blank3).append("\n");
        sb.append(blank4).append("\n");
        sb.append(blank5).append("\n");
        sb.append(blank6).append("\n");

        System.out.println(sb);
    }
}
