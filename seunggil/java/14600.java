import java.util.*;
import java.io.*;

public class _BOJ_DC_G5_14600 {
    static final int[][] delta = {{1,1}, {1,0}, {0,1},{0,0}};

    static int tile = 1;
    static void dc(int[][] map, int r, int c, int dir){
        for(int i = r; i < r+2; i++){
            for(int j = c; j < c+2; j++){
                if(i == (r + delta[dir][0]) && j == (c + delta[dir][1])){
                    map[i][j] = 0;
                }else{
                    map[i][j] = tile;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(re.readLine());
        StringTokenizer token = new StringTokenizer(re.readLine());
        int y = Integer.parseInt(token.nextToken()) -1;
        int x = Integer.parseInt(token.nextToken()) -1;

        n = (int)Math.pow(2,n);


        int[][] map = new int[n][n];
        
        if(n == 2){
            map[0][0] = 1;
            map[1][0] = 1;
            map[0][1] = 1;
            map[1][1] = 1;
            map[x][y] = -1;
        }else{

            int cnt = 0;
            for(int i = 0; i <= 2; i += 2){
                for(int j = 0; j <= 2; j += 2){
                    dc(map,i,j, cnt++);
                    tile++;
                }
            }

            int r;
            if(x < 2){
                r = 0;
            }else{
                r = 2;
            }

            int c;
            if(y < 2){
                c = 0;
            }
            else{
                c = 2;
            }

            for(int i = r; i < r+2; i++){
                for(int j = c; j < c+2; j++){
                    if(i == x && j == y){
                        map[i][j] = -1;
                    }else{
                        map[i][j] = tile;
                    }
                }
            }
            tile++;

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(map[i][j] == 0)
                        map[i][j] = tile;
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                ans.append(map[i][j]).append(' ');
            }ans.append('\n');
        }
        System.out.print(ans);
        re.close();
    }
}
