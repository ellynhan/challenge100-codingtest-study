import java.util.*;
class Solution {
    public int solution(int[] arr) {
        int max=arr[0];
        for(int i=0;i<arr.length;i++){
            if(max<arr[i]){
                max=arr[i];
            }
        }
        int cnt;
        while(true){
            cnt=0;
            for(int i=0;i<arr.length;i++){
                if((max%arr[i])==0){
                    cnt++;
                }
            }
            if(cnt==arr.length){
                return max;
            }
            max++;
        }
    }
}
