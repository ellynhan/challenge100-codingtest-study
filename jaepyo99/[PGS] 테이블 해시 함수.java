import java.util.*;
class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        Arrays.sort(data,new Comparator<int[]>(){
            @Override
            public int compare(int[]a,int[]b){
                if(a[col-1]<b[col-1]){
                    return -1;
                }else if(a[col-1]>b[col-1]){
                    return 1;
                }else{
                    if(a[0]<b[0]){
                        return 1;
                    }else{
                        return -1;
                    }
                }
            }
        });
        // for(int i=0;i<data.length;i++){
        //     for(int j=0;j<3;j++){
        //         System.out.print(data[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        for(int i=row_begin-1;i<=row_end-1;i++){
            int S_i = 0;
            for (int d : data[i]) S_i += (d % (i + 1));
            answer = (answer ^ S_i);
        }
        
        return answer;
    }
}
