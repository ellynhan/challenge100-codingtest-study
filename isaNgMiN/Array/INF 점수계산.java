// 카운팅: true 1 false 0 연속n자리
//  false +0 continue
//  1번 +1, 처음 true +1
//  연속 n번 +n

// 예외. 첫자리

// 로직. 1->n 포문돌면서 cnt != 0 cnt+1 -> ans+=cnt
//      1. 맞췄을때
//      2. 틀렸을때

import java.util.*;

class Main{

    public static int sol(int n, int[] tt){
        int ans = 0;
        int tans = 0;
        if(tt[0] == 1) {
            ans = tans = 1;
        }

        for(int i=1; i<n; i++){
            if(tt[i] == 1) {tans+=1; ans+=tans;} // 연속으로 맞췄을때
            else tans=0;
        }


        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] tt = new int[n];
        for (int i=0; i<n; i++){
            tt[i] = sc.nextInt();
        }

        System.out.print(sol(n, tt));

    }
}