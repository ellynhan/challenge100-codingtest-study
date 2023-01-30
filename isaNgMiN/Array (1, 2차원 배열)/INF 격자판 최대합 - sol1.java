// NXN 격자판에서 다음중 가장 큰 수
//  1. 행의합
//  2. 열의합
//  3. 대각선 각각의 합(2)

// 로직. 포문 두개 저장만하고 행 열 대, 가장 큰값 출력 max

import java.util.*;

class Main{

    public static long sol(int n, long[][] gggg){
        long ans = 0;
        long[] rs = new long[n];
        long[] cs = new long[n];
        long[] di = new long[2];


        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) di[0] += gggg[i][j]; //대각선\
                if(n-i == j) di[1] += gggg[i][j]; //대각선 /

                rs[i] += gggg[i][j];
                cs[j] += gggg[i][j];
            }
        }

        long tmp = Math.max(Arrays.stream(rs).max().getAsLong(), Arrays.stream(cs).max().getAsLong());
        long tmp2 = Math.max(di[0], di[1]);
        ans = Math.max(tmp, tmp2);

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] gggg = new long[n][n];
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                gggg[i][j] = sc.nextLong();
            }
        }

        System.out.print(sol(n, gggg));
    }
}