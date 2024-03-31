import java.util.*;
class Solution {
    public String solution(int n) {
        StringBuilder sb=new StringBuilder();
        while(n>0){
            int r=n%3;
            if(r==0){
                sb.append(4);
            }else if(r==1){
                sb.append(1);
            }else if(r==2){
                sb.append(2);
            }
            if(r==0){
                n-=1;
            }
            n/=3;
        }
        return sb.reverse().toString();
    }
}
