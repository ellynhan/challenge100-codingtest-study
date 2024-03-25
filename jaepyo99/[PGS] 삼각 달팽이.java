import java.util.*;
class Solution {
    public int[] solution(int n) {
        int[][] arr=new int[n][n];
        List<Integer>list=new ArrayList<>();
        for(int i=0;i<n;i++){
            Arrays.fill(arr[i],0);    
        }
        
        int num=1;
        int r=-1;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i%3==0){
                    arr[++r][c]=num++;
                    
                }else if(i%3==1){
                    arr[r][++c]=num++;
                }else if(i%3==2){
                    arr[--r][--c]=num++;
                }    
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                    continue;
                }
                list.add(arr[i][j]);
            }
        }
        
        int[] answer=new int[list.size()];
        for(int i=0;i<list.size();i++){
            answer[i]=list.get(i);
        }
        return answer;
    }
}
