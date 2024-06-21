import java.util.*;
class Solution{
    public int solution(String s){
        int n=s.length();
        for(int i=n;i>=1;i--){
            for(int j=0;j+i<=n;j++){
                if(isPal(s,j,i+j-1)){
                    return i;
                }
            }
        }    
        return 0;
    }
    public boolean isPal(String s,int start,int end){
        while(start<=end){
            if(s.charAt(start++)!=s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
}
