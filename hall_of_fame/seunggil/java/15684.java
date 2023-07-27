import java.util.*;
import java.io.*;

public class _BOJ_DFS_G4_15684 {
    static int[][] map;
    static int n;
    static int m;

    static int ans = Integer.MAX_VALUE;

    // 사다리 내려가기
    static void cal(int ladderCnt){
        boolean result = true;

        for(int i = 0; i < m; i++){
            int x = 0;
            int y = i;

            if(map[x][y] != -1){
                y = map[x][y];
            }

            while(x < n-1){
                x++;
                if(map[x][y] != -1){
                    y = map[x][y];
                }
            }
            if(y != i){
                result = false;
                break;
            }
        }

        if(result){
            ans = Integer.min(ladderCnt, ans);
        }
    }

    static void dfs(int idx, int now, int want){
        if(ans != Integer.MAX_VALUE)
            return;

        if(now == want){
            cal(now);
            return;
        }

        for(int i = idx, len = n*m; i < len; i++){
            int x = i / m;
            int y = i % m;

            if(map[x][y] == -1){
                if(y+1 < m && map[x][y+1] == -1){
                    map[x][y+1] = y;
                    map[x][y] = y+1;
                    dfs(x*m+y+2,now+1, want);
                    map[x][y+1] = -1;
                    map[x][y] = -1;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());
        m = Integer.parseInt(token.nextToken());
        int ladderCnt = Integer.parseInt(token.nextToken());
        n = Integer.parseInt(token.nextToken());

        map = new int[n][m];

        for(int i = 0; i < n; i++){
            Arrays.fill(map[i], -1);
        }

        for(int i = 0; i < ladderCnt; i++){
            token = new StringTokenizer(re.readLine());

            int a = Integer.parseInt(token.nextToken())-1;
            int b = Integer.parseInt(token.nextToken())-1;

            map[a][b] = b + 1;
            map[a][b+1] = b;
        }
        int t = Integer.min((m-1)*n,3);
        for(int i = 0; i <= t; i++){
            dfs(0,0,i);
            if(ans != Integer.MAX_VALUE)
                break;
        }
        if(ans == Integer.MAX_VALUE)
            System.out.print(-1);
        else
            System.out.print(ans);

        re.close();
    }
}
