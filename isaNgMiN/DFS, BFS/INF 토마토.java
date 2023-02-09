// 토마토 땅따먹기
//  사방향 1확장, 모든 토마토가 1이 될때의 d
//  1 익었 / 0 안익 / -1 토마토없

// bfs.

import java.util.*;

class Coor{
    int x;
    int y;
    public Coor(int x, int y){
        this.x=x;
        this.y=y;
    }
}

class Main{

    static int total = 0;
    static int comp = 0;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};
    public static int bfs(int n, int m, int[][] t){
        Queue<Coor> bq = new LinkedList<>();

        int d=0;
        //init
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t[i][j] == 1) bq.add(new Coor(i,j));
            }
        }

        while(!bq.isEmpty()){
            int sz = bq.size();
            d+=1;
            for(int i=0; i<sz; i++){
                Coor tmp = bq.poll();
                for(int j=0; j<4; j++){
                    int nx = tmp.x + dx[j];
                    int ny = tmp.y + dy[j];

                    if(t[nx][ny] != 0) continue;
                    comp += 1;
                    if(comp == total) return d;
                    t[nx][ny] = 1;
                    bq.offer(new Coor(nx,ny));

                }
            }
        }

        return -1;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] t = new int[n+2][m+2];
        for(int i=0; i<n+2; i++){
            for(int j=0; j<m+2; j++){
                if(i==0 || i==n+1 || j==0 || j == m+1) t[i][j] = -1;
                else {
                    t[i][j] = sc.nextInt();
                    if (t[i][j] == 0) total += 1;
                }
            }
        }

        System.out.print(bfs(n,m,t));
    }
}