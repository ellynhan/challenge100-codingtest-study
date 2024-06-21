import java.util.*;
class Solution {
    static class Point{
        int x,y,dir,cost;
        Point(int x,int y,int dir, int cost){
            this.x=x;
            this.y=y;
            this.dir=dir;
            this.cost=cost;
        }
    }
    static boolean[][] visit;
    static int answer;
    static int n;
    static int[][][]arr;
    public int solution(int[][] board) {
        answer=Integer.MAX_VALUE;
        n=board.length;
        arr=new int[4][n][n];
        for(int i=0;i<4;i++){
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    arr[i][x][y]=Integer.MAX_VALUE;
                }
            }
        }
        visit=new boolean[n][n];
        bfs(0,0,-1,0,board);
        return answer;
    }
    private void bfs(int x,int y,int dir,int cost,int[][]board){
        int[]dx={-1,1,0,0};
        int[]dy={0,0,-1,1};
        Queue<Point>q=new LinkedList<>();
        q.add(new Point(x,y,dir,cost));
        visit[x][y]=true;
        while(!q.isEmpty()){
            Point point=q.poll();
            int px=point.x;
            int py=point.y;
            int pdir=point.dir;
            int pcost=point.cost;
            if(px==n-1 && py==n-1){
                answer=Math.min(answer,pcost);
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=px+dx[i];
                int ny=py+dy[i];
                int ndir=i;
                int ncost=pcost;
                if(nx<0 ||nx>=n||ny<0||ny>=n||board[nx][ny]==1){
                    continue;
                }
                if(pdir==-1){
                    ncost+=100;
                }else if(pdir==ndir){
                    ncost+=100;
                }else{
                    ncost+=600;
                }
                
                if(!visit[nx][ny] || arr[ndir][nx][ny]>=ncost){
                    visit[nx][ny]=true;
                    arr[ndir][nx][ny]=ncost;
                    q.add(new Point(nx,ny,ndir,ncost));
                }
            }
        }
    }
}
