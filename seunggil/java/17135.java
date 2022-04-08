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
public class Main {
    static final int[][] delta = {{0,-1}, {-1,0}, {0,1}};
    static int n;
    static int m;
    static int d;
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer token = new StringTokenizer(re.readLine());
        n = Integer.parseInt(token.nextToken());
        m = Integer.parseInt(token.nextToken());
        d = Integer.parseInt(token.nextToken());

        int[][] map = new int[n][m];

        for(int i = 0; i < n; i++){
            token = new StringTokenizer(re.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(token.nextToken());
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                for(int k = j+1; k < m; k++){
                    ans = Integer.max(ans, bfs(map,new int[]{i,j,k}, d, n));
                }
            }
        }
        System.out.print(ans);
        re.close();
    }

    static int bfs(int[][] map, int[] hunters, int len, int time){
        int answer = 0;

        int[][] copyMap = new int[n][];

        for(int i = 0; i < n; i++){
            copyMap[i] = Arrays.copyOf(map[i], m);
        }

        for(int i = 0; i < time; i++){
            ArrayList<Pos> hunted = new ArrayList<>();
            for(int hunter : hunters){
                boolean[][] visited = new boolean[n][m];
                Queue<Pos> bfs = new ArrayDeque<>();

                if(copyMap[n-1][hunter] == 1){
                    hunted.add(new Pos(n-1,hunter));
                }else{
                    visited[n-1][hunter] = true;
                    bfs.add(new Pos(n-1, hunter));

                    int d = 1;
                    outer : while(!bfs.isEmpty() && d <= len){
                        int size = bfs.size();

                        for(int j = 0; j < size; j++){
                            Pos now = bfs.poll();
                            if(copyMap[now.x][now.y] == 1){
                                hunted.add(now);
                                break outer;
                            }else{
                                for(int k = 0; k < 3; k++){
                                    int nextX = now.x + delta[k][0];
                                    int nextY = now.y + delta[k][1];

                                    if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !visited[nextX][nextY]){
                                        visited[nextX][nextY] = true;
                                        bfs.add(new Pos(nextX, nextY));
                                    }
                                }
                            }
                        }
                        d++;
                    }
                }

            }
            for(Pos h : hunted){
                Pos now = h;
                if(copyMap[now.x][now.y] == 1){
                    copyMap[now.x][now.y] = 0;
                    answer++;
                }
            }
            
            for(int j = n-2; j >= 0; j--){
                for(int k = 0; k < m; k++){
                    copyMap[j+1][k] = copyMap[j][k];
                }
            }

            for(int j = 0; j < m; j++){
                copyMap[0][j] = 0;
            }

            // for(int j = 0; j < n; j++){
            //     for(int k = 0; k < m; k++){
            //         System.out.print(copyMap[j][k]+ " ");
            //     }System.out.println();
            // }
            // System.out.println("\n");
        }

        return answer;
    }
}
