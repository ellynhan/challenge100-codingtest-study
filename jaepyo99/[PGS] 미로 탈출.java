import java.util.*;
class Solution {
    String[][] miro;
    int[]dx={-1,0,1,0};
    int[]dy={0,1,0,-1};
    public int solution(String[] maps) {
        int answer = 0;
        miro=new String[maps.length][maps[0].length()];
        int[]start=new int[2];
        int[]labor=new int[2];
        for(int i=0;i<maps.length;i++){
            String[]tmp=maps[i].split("");
            for(int j=0;j<tmp.length;j++){
                miro[i][j]=tmp[j];
                if(miro[i][j].equals("S")){
                    start=new int[]{i,j};
                }
                if(miro[i][j].equals("L")){
                    labor=new int[]{i,j};
                }
                
            }
        }
        int result1=bfs(start,"L");
        int result2=bfs(labor,"E");
        if(result1==-1 || result2==-1){
            return -1;
        }
        return result1+result2;
    }
    public int bfs(int[]start,String target){
        Queue<int[]>queue=new LinkedList<>();
        queue.add(new int[]{start[0],start[1],0});//시작 행,열,누적값
        boolean[][]visit=new boolean[miro.length][miro[0].length];
        while(!queue.isEmpty()){
            int[]v=queue.peek();
            int x=v[0];
            int y=v[1];
            int cnt=v[2];
            visit[x][y]=true;
            if(miro[x][y].equals(target)){
                return cnt;
            }
            queue.poll();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                 if (nx >= 0 && nx < miro.length && ny >= 0 && ny < miro[0].length && !visit[nx][ny]){
                     if(!miro[nx][ny].equals("X")){
                         visit[nx][ny]=true;
                         queue.add(new int[]{nx,ny,cnt+1});
                     }
                 }
            }
        }
        return -1;
    }
}
