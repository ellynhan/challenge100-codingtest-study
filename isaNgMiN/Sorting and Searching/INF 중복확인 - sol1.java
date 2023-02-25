// N중 중복체크

// 어레이리스트

import java.util.*;
class Main{

    public static String sol(int n,long[] t){
        String ans = "U";
        ArrayList<Long> a = new ArrayList<>();

        for(long x : t){
            if(a.contains(x)) return "D";
            else a.add(x);
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