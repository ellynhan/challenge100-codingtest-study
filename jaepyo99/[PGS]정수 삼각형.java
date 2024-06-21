class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int r=triangle.length;
        for(int i=r-1;i>0;i--){
            int c=triangle[i].length;
            for(int j=0;j<c-1;j++){
                triangle[i-1][j]+=Math.max(triangle[i][j],triangle[i][j+1]);
            }
        }
        return triangle[0][0];
    }
}
