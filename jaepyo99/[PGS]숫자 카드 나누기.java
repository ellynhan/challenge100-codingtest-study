import java.util.*;
class Solution {
    private int gcd(int[]arr){
        int result=arr[0];
        for(int i=1;i<arr.length;i++){
            result=gcd(result,arr[i]);
        }
        return result;
    }
    private int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    private boolean verify(int[]arr,int gcd){
        int cnt=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]%gcd==0){
                cnt++;
            }
        }
        if(cnt>0){
            return false;
        }
        return true;
    }
    public int solution(int[] arrayA, int[] arrayB) {
        int gcdA=gcd(arrayA);
        boolean a=verify(arrayB,gcdA);
        
        int gcdB=gcd(arrayB);
        boolean b=verify(arrayA,gcdB);
        
        if(a && b){
            return Math.max(gcdA,gcdB);
        }
        else if(a){
            return gcdA;
        }
        else if(b){
            return gcdB;
        }
        return 0;
    }
}
