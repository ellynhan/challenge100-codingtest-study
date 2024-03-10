import java.util.*;
class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = {};
        answer=new int[arr1.length][arr2[0].length];
            for(int k=0;k<arr1.length;k++){
                for(int j=0;j<arr2[0].length;j++){
                    int sum=0;
                    for(int i=0;i<arr2.length;i++){
                        sum+=arr1[k][i]*arr2[i][j];
                    }
                    answer[k][j]=sum;
                }
            }
        return answer;
    }
}
