import java.util.*;
class Solution {
    private String calculate(int n,int k){
        StringBuilder sb=new StringBuilder();
        while(n>0){
            sb.append(Integer.toString(n%k));
            n=n/k;
        }   
        sb.reverse();
        return sb.toString();
    }
    private Double calToOriginal(String prime,int k){
        int c=0;
        Double a=0.0;
            System.out.println(prime);
        for(int i=prime.length()-1;i>=0;i--){
            Double b=Character.getNumericValue(prime.charAt(i))*(Math.pow(k,c));
            c++;
            a += b;
        }
        return a;
    }
    private boolean isPrime(long can){
        if(can<=1){
            return false;
        }
        else if(can==2){
            return true;
        }
        for(int i=2;i<Math.sqrt(can)+1;i++){
            if(can%i==0){
                return false;
            }
        }
        return true;
    }
    public int solution(int n, int k) {
        int answer = 0;
        String s=calculate(n,k);
        
        int i,j;
        for(i = 0; i < s.length(); i = j) {
            for(j = i + 1; j < s.length() && s.charAt(j) != '0'; j++);
            if(isPrime(Long.parseLong(s.substring(i,j))))
                answer++;
        }
        return answer;
    }
}
