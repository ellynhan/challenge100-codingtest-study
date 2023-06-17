import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int wire[][] = new int[N][2];
        int dp[] = new int[N];

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            wire[i][0] = Integer.parseInt(st.nextToken());
            wire[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(wire, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        for(int i = 0; i < N; i++) {
            dp[i] = 1;

            for(int j = 0; j < i; j++)
                if(wire[i][1] > wire[j][1])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
        }

        int max = 0;
        for(int i = 0; i < N; i++)
            max = Math.max(max, dp[i]);


        sb.append(N - max).append("\n");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}