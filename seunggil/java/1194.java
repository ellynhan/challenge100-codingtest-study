import java.util.*;
import java.io.*;

class Pos{
    int x;
    int y;

    int status;

    public Pos(int x, int y, int status) {
        this.x = x;
        this.y = y;
        this.status = status;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Pos other = (Pos) obj;
        if (x != other.x)
            return false;
        if (y != other.y)
            return false;
        return true;
    }

    

}

public class Main2{
    public static void main(String[] args) throws IOException {
        final int[][] delta = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        final int wall = 0;
        final int blank = Integer.MAX_VALUE;
        final int exit = Integer.MIN_VALUE;
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
    
        StringTokenizer token = new StringTokenizer(re.readLine());
        int n = Integer.parseInt(token.nextToken());
        int m = Integer.parseInt(token.nextToken());

        int[][] map = new int[n][m];
        boolean[][][] dp = new boolean[64][n][m];

        Queue<Pos> bfs = new ArrayDeque<>();

        for(int i = 0; i < n; i++){
            String s = re.readLine();
            for(int j = 0; j < m; j++){
                char c = s.charAt(j);

                switch (c) {
                    case '0':
                        bfs.add(new Pos(i,j, 0));
                        dp[0][i][j] = true;
                        map[i][j] = blank;
                        break;
                
                    case '1':
                        map[i][j] = exit;
                        break;

                    case '#':
                        map[i][j] = wall;
                        break;

                    case '.':
                        map[i][j] = blank;
                        break;

                    default:
                        if(Character.isUpperCase(c)){
                            // 1번 열쇠가 필요하면 000001 이렇게 저장
                            map[i][j] = (1 << (c - 'A'));
                        }else if(Character.isLowerCase(c)){
                            // 1번 열쇠가 얻을 수 있으면 000001를 음수로 저장
                            map[i][j] = -(1 << (c - 'A'));
                        }
                    break;
                }

            }
        }

        int ans = 0;
        while(!bfs.isEmpty()){
            int size = bfs.size();
            ans++;

            while(size-- > 0){
                Pos now = bfs.poll();

                if(map[now.x][now.y] == exit){
                    System.out.print(ans - 1);
                    return;
                }

                for(int i = 0; i < 4; i++){
                    int nextX = now.x + delta[i][0];
                    int nextY = now.y + delta[i][1];
                    int keyStatus = now.status;

                    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m){
                        continue;
                    }

                    if(map[nextX][nextY] == blank || map[nextX][nextY] == exit){
                        if(!dp[keyStatus][nextX][nextY]){
                            dp[keyStatus][nextX][nextY] = true;
                            bfs.add(new Pos(nextX, nextY, keyStatus));
                        }
                    }else if(map[nextX][nextY] < 0){ // 열쇠획득
                        keyStatus |= -(map[nextX][nextY]);
                        if(!dp[keyStatus][nextX][nextY]){
                            dp[keyStatus][nextX][nextY] = true;
                            bfs.add(new Pos(nextX, nextY, keyStatus));
                        }
                    }
                    else{
                        if((keyStatus & map[nextX][nextY]) != 0 && !dp[keyStatus][nextX][nextY]){
                            dp[keyStatus][nextX][nextY] = true;
                            bfs.add(new Pos(nextX, nextY, keyStatus));
                        }
                    }
                }
            }
        }

        System.out.print(-1);
        re.close();
    }
}