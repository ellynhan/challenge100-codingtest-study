

import java.util.*;

class Main{

    static long[] f;

    public static long recur(int n){
        if(f[n]>0) return f[n];
        else if(n==1 || n==2) return f[n] = 1;
        else{
            return f[n] = recur(n-1) + recur(n-2);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        f = new long[n+1];
        recur(n);
        for(int i=1; i<=n; i++) {
            System.out.print(f[i] + " ");
        }

    }
}