import java.util.*;
// 나누기 2한만큼의 위치까지 일단 오면됌
// 즉 처음값의 나누기2의 위치로 가기 -> 해당 위치의 나누기 2위치 -> 반복해서 
public class Solution {
    public int solution(int n) {
        int ans = 0;
        while(n>0){
            if(n%2==0){
                n=n/2;
            }else{
                n=n-1;
                ans+=1;
            }
        }                     
        return ans;
    }
}
