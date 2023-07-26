import java.util.*;
import java.io.*;

class Pos{
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
}

public class Main2{
    public static void main(String[] args) throws IOException {
        final int[][] delta = {{0,1}, {1,0}, {-1,0},{0,-1}};
        final int INF = 1250;

        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int testCase = 1;
        StringBuilder ans = new StringBuilder();
        while(true){
            int n = Integer.parseInt(re.readLine());
            if(n == 0)
                break;

            int[][] inputData = new int[n][n];

            for(int i = 0; i < n; i++){
                StringTokenizer token = new StringTokenizer(re.readLine());
                for(int j = 0; j < n; j++){
                    inputData[i][j] = Integer.parseInt(token.nextToken());
                }
            }

            int[][] dp = new int[n][n];

            for(int i = 0; i < n; i++)
                Arrays.fill(dp[i], INF);
            
            dp[0][0] = inputData[0][0];

            Queue<Pos> bfs = new ArrayDeque<>();
            bfs.offer(new Pos(0, 0));

            while(!bfs.isEmpty()){
                Pos now = bfs.poll();

                for(int i = 0; i < 4; i++){
                    int nextX = now.x + delta[i][0];
                    int nextY = now.y + delta[i][1];

                    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                        continue;

                    if(dp[nextX][nextY] > dp[now.x][now.y] + inputData[nextX][nextY]){
                        dp[nextX][nextY] = dp[now.x][now.y] + inputData[nextX][nextY];
                        bfs.offer(new Pos(nextX, nextY));
                    }
                }
            }

            ans.append("Problem ").append(testCase++).append(": ").append(dp[n-1][n-1]).append('\n');
        }

        System.out.print(ans);
        re.close();
    }
}