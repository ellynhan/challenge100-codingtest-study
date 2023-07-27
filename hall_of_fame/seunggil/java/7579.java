import java.util.*;
import java.io.*;

public class Main2{
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());

        final int MAX_COST = 10_001;

        int n = Integer.parseInt(token.nextToken());
        int needMemory = Integer.parseInt(token.nextToken());

        int[] memory = new int[n];
        int[] cost = new int[n];

        token = new StringTokenizer(re.readLine());
        for(int i = 0; i < n; i++){
            memory[i] = Integer.parseInt(token.nextToken());
        }

        token = new StringTokenizer(re.readLine());
        for(int i = 0; i < n; i++){
            cost[i] = Integer.parseInt(token.nextToken());
        }

        int[][] dp = new int[n][MAX_COST];
        
        for(int i = cost[0]; i < MAX_COST; i++){
            dp[0][i] = memory[0];
        }

        int ans = MAX_COST;
        if(memory[0] >= needMemory)
            ans = cost[0];
        
        int nowMemory = 0;
        for(int i = 0; i < n; i++){
            if(cost[i] == 0){
                nowMemory = Math.max(memory[i], nowMemory);
                if(needMemory <= nowMemory){
                    System.out.print(0);
                    return;
                }
            }
            dp[i][0] = nowMemory;
        }
        
        
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < ans; j++){
                if(cost[i] <= j)
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);

                dp[i][j] = Math.max(dp[i][j], dp[i][j-1]);
                dp[i][j] = Math.max(dp[i][j], dp[i-1][j]);

                if(dp[i][j] >= needMemory && j < ans){
                    ans = j;
                }
            }
        }

        System.out.print(ans);
        re.close();
    }

}