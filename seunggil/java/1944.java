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
public class _BOJ_MST_G2_1944{
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());

        int n = Integer.parseInt(token.nextToken());
        int m = Integer.parseInt(token.nextToken());

        char[][] map = new char[n][];
        
        for(int i = 0; i < n; i++){
            map[i] = re.readLine().toCharArray();
        }
        re.close();
        
        final int[] dx = {0, 1, -1, 0};
        final int[] dy = {1, 0, 0,-1};
        
        ArrayList<Integer> checkedPos = new ArrayList<>();
        
        Queue<Pos> bfs = new ArrayDeque<>();
        
        boolean[][] visited = new boolean[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 'S'){
                    bfs.add(new Pos(i, j));
                    visited[i][j] = true;
                    checkedPos.add(i*n+j);
                    break;
                }
            }
        }
        
        int[][] debugAnswer = new int[n][n];
        
        int ans = 0;
        int len = 0;
        while(m != (checkedPos.size() -1) && !bfs.isEmpty()){
            len++;
            int size = bfs.size();

            while(size-- > 0){

                Pos now = bfs.poll();

                for(int i = 0; i < 4; i++){
                    int nextX = now.x + dx[i];
                    int nextY = now.y + dy[i];
                    
                    if(visited[nextX][nextY])
                        continue;
                    if(map[nextX][nextY] == 'K'){
                        debugAnswer[nextX][nextY] = len;
                        ans += len;
                        checkedPos.add(nextX*n + nextY);
                        len = 0;
                        size = 0;
                        bfs.clear();

                        visited = new boolean[n][n];
                        for(int iter : checkedPos){
                            bfs.add(new Pos(iter / n, iter % n));
                            visited[iter / n][iter % n] = true;
                        }

                        break;
                    }else if(map[nextX][nextY] == '0'){
                        visited[nextX][nextY] = true;
                        bfs.add(new Pos(nextX, nextY));
                    }
                }

            }

            if(bfs.isEmpty()){
                System.out.print(-1);
                return;
            }
        }
        System.out.println(ans);

    }
}