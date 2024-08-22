import java.util.*;
class Solution {
    public int solution(int[] stones, int k) {
        Integer min=1;
        Integer max=200000000;
        int answer=0;
        while(min<=max){
            Integer mid=(max+min)/2;
            if(check(mid,k,stones)){
                min=mid+1;
                answer=mid;
            }else{
                max=mid-1;
            }
        }
        return answer;
    }
    public boolean check(Integer mid,int k,int[]stones){
        int a=0;
        for(int stone:stones){
            if(stone-mid<0){
                a++;
            }else{
                a=0;
            }
            if(a==k){
                return false;
            }
        }
        return true;
    }
}
