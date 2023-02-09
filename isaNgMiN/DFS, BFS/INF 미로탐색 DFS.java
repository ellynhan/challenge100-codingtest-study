// 미로 탈출 경로의 경우의수

// dfs
//  디렉션 진행
//  7,7 +=1 / direction no with check 그냥 포문 지나가

import java.util.*;

class Main{

    static int[][] b = new int[9][9];
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};
    static int ans=0;

    public static void dfs(int d, int cx, int cy){
        if(cx == 7 && cy ==7){
            ans+=1;
        }else{
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(b[nx][ny] == 1) continue;
                b[nx][ny] = 1;
                dfs(d+1, nx, ny);
                b[nx][ny] = 0;
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(i==0 || j==0 || i==8 || j==8) b[i][j] = 1;
                else b[i][j] = sc.nextInt();
            }
        }

        b[1][1]= 1;
        dfs(0,1,1);

        System.out.print(ans);

    }
}