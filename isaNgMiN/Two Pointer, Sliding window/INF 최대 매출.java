// N일중, 연속K일동안의, 최대합

// 고려. 첫K, 마지막K

// 로직. for -> -lt +rt
//          if new rt > old lt : ans update

import java.util.*;

class Main{
    public static long sol(int n, int k, ArrayList<Long> gg){
        long ans = 0;
        long tans = 0;

        for(int j=0; j<k; j++){
            tans += gg.get(j);
            ans = tans;
        }

        for(int lt=0; lt<n-k; lt++){
            tans = tans - gg.get(lt) + gg.get(lt+k);
            if(tans > ans) ans = tans;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        ArrayList<Long> gg = new ArrayList<>();
        for(int i=0; i<n; i++){
            gg.add(sc.nextLong());
        }

        System.out.print(sol(n,k,gg));
    }
}
