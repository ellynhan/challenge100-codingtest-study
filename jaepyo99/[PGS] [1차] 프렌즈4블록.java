import java.util.*;
class Solution {
    static private char arr[][];
    static int answer=0;
    private static class Vertex{
            int r;
            int c;
            public Vertex(int r,int c){
                this.r=r;
                this.c=c;
            }
        }
    public int solution(int m, int n, String[] board) {
        arr=new char[m][n];
        for(int i=0;i<board.length;i++){
            char[] temp=board[i].toCharArray();
            for(int j=0;j<temp.length;j++){
                arr[i][j]=temp[j];
            }
        }
        
        while(true){
            if(!removeAndCheck()){
                break;
            }
            down();
        }
        
        return answer;
    }
    public static boolean removeAndCheck(){
        int cnt=0;
        List<Vertex>list=new ArrayList<>();
        for(int i=0;i<arr.length-1;i++){
            for(int j=0;j<arr[0].length-1;j++){
                if(arr[i][j]=='.'){
                    continue;
                }
                if(arr[i][j]==arr[i][j+1]&&arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i+1][j+1]){
                    list.add(new Vertex(i,j));
                    list.add(new Vertex(i,j+1));
                    list.add(new Vertex(i+1,j));
                    list.add(new Vertex(i+1,j+1));
                }
            }
        }
        
        Iterator<Vertex>iter=list.iterator();
        while(iter.hasNext()){
            Vertex v=iter.next();
            if(arr[v.r][v.c]=='.'){
                continue;
            }else if(arr[v.r][v.c]!='.'){
                cnt++;
                arr[v.r][v.c]='.';
            }
        }
        answer+=cnt;
        if(cnt==0){
            return false;
        }
        return true;
    }
    public static void down(){
        for(int i=0;i<arr[0].length;i++){
            int space=0;
            for(int j=arr.length-1;j>=0;j--){
                if(arr[j][i]=='.'){
                    space++;
                }else if(arr[j][i]!='.'&&space!=0){
                    arr[j+space][i]=arr[j][i];
                    arr[j][i]='.';
                }
            }
        }
    }
}
