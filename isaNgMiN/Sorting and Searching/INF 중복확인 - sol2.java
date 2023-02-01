// N중 중복체크

// 어레이리스트

import java.util.*;
class Main{

    public static String sol(int n,long[] t){
        String ans = "U";

        Arrays.sort(t);

        for(int i=0; i<n-1; i++){
            if(t[i] == t[i+1]) return "D";
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] t = new long[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextLong();
        }

        System.out.print(sol(n,t));
    }
}