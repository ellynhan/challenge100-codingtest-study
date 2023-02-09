// N개의수 -> 랭킹처리

// 고려. 같은수 -> 동일랭킹 -> 뒤의 랭킹은 하나씩 밀려서

// 로직. 2중포문 나보다 큰 수의 개수
//      1. 동일랭킹 ㅇ
//      2. 동일랭킹다음 ㅇ

import java.util.*;

class Main{

    public static long[] sol(int n, long[] tt){
        long[] ans = new long[n];

        for(int i=0; i<n; i++){
            long cnt = 1;
            for(int j=0; j<n; j++){
                if(tt[i] < tt[j]) cnt+=1;
            }
            ans[i] = cnt;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long tt[] = new long[n];
        for(int i=0; i<n; i++){
            tt[i] = sc.nextLong();
        }

        long ans[] = sol(n, tt);
        for(int i=0; i<n; i++){
            System.out.print(ans[i] + " ");
        }

    }
}