class Solution {
    private int one=0;
    private int zero=0;
    
    public void bfs(int startR,int startC,int size,int[][]arr){
        if(size==1){
            if(arr[startR][startC]==1){
                one++;
            }else{
                zero++;
            }
            return;
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(arr[startR][startC]!=arr[startR+i][startC+j]){
                    bfs(startR,startC,size/2,arr);
                    bfs(startR+size/2,startC,size/2,arr);
                    bfs(startR,startC+size/2,size/2,arr);
                    bfs(startR+size/2,startC+size/2,size/2,arr);
                    return;
                }
            }
        }
        if(arr[startR][startC]==1){
                one++;
            }else{
                zero++;
            }
        
        
    }
    public int[] solution(int[][] arr) {
        int[] answer = new int[2];
        bfs(0,0,arr.length,arr);
        answer[0]=zero;
        answer[1]=one;
        return answer;
    }
}
