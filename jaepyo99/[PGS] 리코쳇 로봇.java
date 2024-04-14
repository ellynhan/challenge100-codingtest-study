// 뭔가 dp
// 100*100이면 n^2이니까 bfs, dfs 가능할듯..?

// 끝점만 큐에 집어넣기?
// 시작에서 상하좌우로 이동해서 부딫히는애들을 큐에 넣기?
// 상하좌우? 정해진 방향으로 끝까지가는 메서드로 빼기?
// map에 표시하기?

import java.util.*;
class Solution {
    int[]dx={-1,1,0,0};
    int[]dy={0,0,-1,1};
    int n,m;
    private class Moving{
        int x,y,depth;
        public Moving(int x,int y,int depth){
            this.x=x;
            this.y=y;
            this.depth=depth;
        }
    }
    public int solution(String[] board) {
        int answer = 0;
        n=board.length;
        m=board[0].length();
        Moving robot=null;
        Moving goal=null;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i].charAt(j);
                if(ch=='R'){
                    robot=new Moving(i,j,0);
                }else if(ch=='G'){
                    goal=new Moving(i,j,0);
                }
            }
        }
        answer=bfs(board,robot,goal);
        
        return answer;
    }
    public int bfs(String[] board,Moving robot,Moving goal){
        Queue<Moving>queue=new LinkedList<>();
        queue.add(robot);
        boolean[][]visit=new boolean[n][m];
        visit[robot.x][robot.y]=true;
        while(!queue.isEmpty()){
            Moving cn=queue.poll();
            if(cn.x==goal.x && cn.y==goal.y){
                return cn.depth;
            }
            for(int i=0;i<4;i++){
                int nx=cn.x;
                int ny=cn.y;
                while(inRange(nx,ny)&&board[nx].charAt(ny)!='D'){
                    nx+=dx[i];
                    ny+=dy[i];
                }
                nx-=dx[i];
                ny-=dy[i];
                if(visit[nx][ny]||(cn.x==nx && cn.y==ny)){
                    continue;
                }
                    visit[nx][ny]=true;
                    queue.add(new Moving(nx,ny,cn.depth+1));
                }
            }
            return -1;
        }
    public boolean inRange(int x,int y){
        return x>=0&&y>=0&&x<n&&y<m;
    }
}
