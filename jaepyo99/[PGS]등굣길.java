import java.util.*;
class Solution {
    int[][]visit;
    int INFINITE=Integer.MAX_VALUE;
    public int dynamic(int x,int y){
        int xv=0,yv=0;
        if(visit[y][x]==-1){
            return 0;
        }
        if(x-1>=0){
            if(visit[y][x-1]>0){
                xv=visit[y][x-1];       
            }else{
                xv=dynamic(x-1,y);
            }
        }
        if(y-1>=0){
            if(visit[y-1][x]>0){
                yv=visit[y-1][x];                
            }else{
                yv=dynamic(x,y-1);
            }
        }
        if(x==0 && y==0){
            return 1;           
        }
        visit[y][x]=(xv+yv)%1000000007;
        return (xv+yv)%1000000007;
    }
    public int solution(int m, int n, int[][] puddles) {
        visit=new int[n][m];
        for(int i=0;i<puddles.length;i++){
            visit[puddles[i][1]-1][puddles[i][0]-1]=-1;
        }
        return dynamic(m-1,n-1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         System.out.print(visit[i][j]);
        //     }
        //     System.out.println();
        // }
    }
}
