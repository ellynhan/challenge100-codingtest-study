import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes,new Comparator<>(){
            @Override
            public int compare(int[]o1,int[]o2){
                if(o1[0]==o2[0]){
                    return o1[1]-o2[1];
                }else{
                    return o1[0]-o2[0];
                }
            }
        });
        // for(int i=0;i<routes.length;i++){
        //     System.out.print("1 :"+routes[i][0]+", 2 :"+routes[i][1]);
        //     System.out.println();
        // }
        int cnt=1;
        int left=routes[0][0];
        int right=routes[0][1];
        for(int i=1;i<routes.length;i++){
            if(left<=routes[i][0] && routes[i][0]<=right){
                left=routes[i][0];
                if(routes[i][1]<=right){
                    right=routes[i][1];
                }
            }else{
                left=routes[i][0];
                right=routes[i][1];
                cnt++;
            }
        }
        return cnt;
    }
}
