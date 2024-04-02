import java.util.*;
class Solution {
    int[][]arr;
    int min;
    public void print2arr(int[][]arr,String msg){
        System.out.println(msg);
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int anum=0;
        arr=new int[rows][columns];
        int num=1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                arr[i][j]=num++;
            }
        }
        
        for(int i=0;i<queries.length;i++){
            for(int j=0;j<queries[0].length;j++){
                queries[i][j]-=1;
            }
        }    
        System.out.println(queries.length);
        for(int i=0;i<queries.length;i++){
            List<Integer>list=new ArrayList<>();
            int r1=queries[i][0];
            int c1=queries[i][1];
            int r2=queries[i][2];
            int c2=queries[i][3];
            
            for(int c=c1;c<c2;c++){
                list.add(arr[r1][c]);
            }
            for(int r=r1;r<r2;r++){
                list.add(arr[r][c2]);
            }
            for(int c=c2;c>c1;c--){
                list.add(arr[r2][c]);
            }
            for(int r=r2;r>r1;r--){
                list.add(arr[r][c1]);
            }
            
            list.add(0,list.get(list.size()-1));
            list.remove(list.size()-1);
            
            int l =0;
            
            for(int c=c1;c<c2;c++){
                arr[r1][c]=list.get(l++);
            }
            for(int r=r1;r<r2;r++){
                arr[r][c2]=list.get(l++);
            }
            for(int c=c2;c>c1;c--){
                arr[r2][c]=list.get(l++);
            }
            for(int r=r2;r>r1;r--){
                arr[r][c1]=list.get(l++);
            }
            answer[anum++]=Collections.min(list);
        }
        
        return answer;
    }
}
