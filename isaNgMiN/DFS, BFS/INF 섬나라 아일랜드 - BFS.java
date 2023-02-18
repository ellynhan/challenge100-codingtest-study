// 1은 섬 / 0은 바다
// 8방향

// DFS
//  DFS8방향 쭉 -> 종료되면 다음 섬찾기 for

import java.util.*;

class Coor{
    int x;
    int y;
    public Coor(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Main{

    static int n;
    static int[][] b;
    static int[] dx = {1,1,0,-1,-1,-1,0,1};
    static int[] dy = {0,-1,-1,-1,0,1,1,1};

    public static int bfs(){
        Queue<Coor> bq = new LinkedList<>();

        int ans = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(b[i][j] == 0) continue;

                b[i][j] = 0;
                bq.add(new Coor(i,j));
                ans+=1;

                while(!bq.isEmpty()){
                    Coor tmp = bq.poll();
                    for(int d=0; d<8; d++){
                        int nx = tmp.x + dx[d];
                        int ny = tmp.y + dy[d];
                        if(b[nx][ny] == 0) continue;

                        b[nx][ny] = 0;
                        bq.offer(new Coor(nx, ny));
                    }
                }

            }
        }

        return ans;

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

        System.out.print(bfs());

    }
}