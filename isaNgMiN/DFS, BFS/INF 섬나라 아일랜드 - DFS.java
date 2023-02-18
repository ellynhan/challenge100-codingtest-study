// 1은 섬 / 0은 바다
// 8방향

// DFS
//  DFS8방향 쭉 -> 종료되면 다음 섬찾기 for

import java.util.*;

class Main{

    static int n;
    static int[][] b;
    static int[] dx = {1,1,0,-1,-1,-1,0,1};
    static int[] dy = {0,-1,-1,-1,0,1,1,1};

    static int island = 0;

    public static void dfs(int d, int cx, int cy){

            for(int i=0; i<8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(b[nx][ny] == 0) continue;
                b[nx][ny] = 0;
                dfs(d+1,nx,ny);
            }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        b = new int[n+2][n+2];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                b[i][j] = sc.nextInt();
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(b[i][j] == 0) continue;
                b[i][j] = 0;
                dfs(0,i,j);
                island += 1;
            }
        }
        System.out.print(island);

    }
}