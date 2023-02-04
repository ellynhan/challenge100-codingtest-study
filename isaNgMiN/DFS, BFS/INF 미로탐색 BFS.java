// 미로 탈출 경로의 경우의수

// dfs
//  디렉션 진행
//  7,7 +=1 / direction no with check 그냥 포문 지나가

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

    static int[][] b = new int[9][9];
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};

    public static int bfs(int d){
        Queue<Coor> bq = new LinkedList<>();

        b[1][1] = 1;
        bq.add(new Coor(1,1));

        while(!bq.isEmpty()){
            int sz = bq.size();
            d+=1;
            for(int i=0; i<sz; i++){
                Coor tmp = bq.poll();
                for(int j=0; j<4; j++) {
                    int nx = tmp.x + dx[j];
                    int ny = tmp.y + dy[j];

                    if(nx==7 && ny==7) return d;
                    if(b[nx][ny] == 1) continue;
                    b[nx][ny] = 1;
                    bq.offer(new Coor(nx,ny));
                }
            }
        }
        return -1;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(i==0 || j==0 || i==8 || j==8) b[i][j] = 1;
                else b[i][j] = sc.nextInt();
            }
        }

        int ans = bfs(0);

        System.out.print(ans);

    }
}