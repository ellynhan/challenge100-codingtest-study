// N입력 -> 연속된 2개이상! 의 자연수의 합 == N 경우의수

// 로직.
//  comp < N rt++ / comp > N lt++
//  ㅇ종료조건


import java.util.*;

class Main{

    public static long sol(long n){
        long ans = 0;
        long lt = 1, rt = 2;
        long comp = 3;

        while(rt <= n/2 + 1){
            if(comp < n) comp+=++rt;
            else if(comp == n) {ans+=1; comp+=++rt;}
            else comp-=lt++;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        System.out.print(sol(n));
    }
}