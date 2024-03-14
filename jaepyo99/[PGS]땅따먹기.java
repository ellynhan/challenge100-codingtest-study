class Solution {
    int solution(int[][] land) {
        int[] answer={0,0,0,0};
            for(int i=1;i<land.length;i++){
                for(int j=0;j<4;j++){
                    int compare=0;
                    for(int k=0;k<4;k++){
                        if(j==k){
                            continue;
                        }
                        if(compare<land[i-1][k]){
                            compare=land[i-1][k];
                        }
                    }
                    land[i][j]+=compare;
                }
            }
            int max=0;
            for(int i=0;i<4;i++){
                if(max<land[land.length-1][i]){
                    max = land[land.length - 1][i];
                }
            }
            return max;
    }
}
