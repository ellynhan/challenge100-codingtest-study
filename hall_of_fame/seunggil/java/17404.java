import java.io.*;
import java.util.*;

public class BOJ_DP_G4_17404 {
    static final int INF = 1000001;
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;

        int n = Integer.parseInt(re.readLine());

        int[][][] dp = new int[3][n][3];

        for (int i = 0; i < n; i++) {
            token = new StringTokenizer(re.readLine());
            
            for (int j = 0; j < 3; j++) {
                int s = Integer.parseInt(token.nextToken());
                dp[0][i][j] = s;
                dp[1][i][j] = s;
                dp[2][i][j] = s;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(i==j){
                    dp[i][1][i] = INF; 
                    dp[i][n-1][i] = INF;
                }else{
                    dp[i][0][j] = INF;
                }
            }
        }

        for (int i = 0; i < 3; i++) { // dp index
            for (int j = 1; j < n; j++) { // 몇번째 집
                dp[i][j][0] += Math.min(dp[i][j-1][1], dp[i][j-1][2]);
                dp[i][j][1] += Math.min(dp[i][j-1][0], dp[i][j-1][2]);
                dp[i][j][2] += Math.min(dp[i][j-1][0], dp[i][j-1][1]);
            }
        }
        
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {       // dp index
            for (int j = 0; j < 3; j++) {   // rgb
                answer =  Math.min(answer, dp[i][n-1][j]);
            }
        }
        System.out.print(answer);
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < n; j++) {
        //         System.out.print(dp[i][j][0]+" ");
        //         System.out.print(dp[i][j][1]+" ");
        //         System.out.print(dp[i][j][2]+" ");
        //         System.out.println();
        //     }
        // }

        re.close();
    }
}
