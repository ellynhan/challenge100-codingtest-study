class Solution{
    public int solution(int [][]board){
        int answer=board.length==1 || board[0].length==1 ? 1: 0;
        for(int i=1;i<board.length;i++){
            for(int j=1;j<board[0].length;j++){
                if(board[i][j]!=0){
                    board[i][j]=Math.min(board[i-1][j-1],Math.min(board[i-1][j],board[i][j-1]))+1;
                    answer=Math.max(board[i][j],answer);
                }
            }
        }
        return answer*answer;
    }
}
