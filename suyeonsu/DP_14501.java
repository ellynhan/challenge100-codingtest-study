import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<int[]> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
            lst.add(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
        }

        int[] dp = new int[n+1];
        for (int i = n-1; i >= 0; i--) {
            int t = lst.get(i)[0];
            int p = lst.get(i)[1];
            dp[i] = (i+t <= n) ? Math.max(dp[i+1], dp[i+t] + p) : dp[i+1];
        }
        System.out.println(dp[0]);
    }
}
