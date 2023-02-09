// NXN 격자판에서 다음중 가장 큰 수
//  1. 행의합
//  2. 열의합
//  3. 대각선 각각의 합(2)

// 로직. 포문 두개 저장만하고 행 열 대, 가장 큰값 출력 max

import java.util.*;

class Main{

    public static long sol(int n, long[][] gggg){
        long ans = 0;
        long sum1 = 0, sum2 = 0;

        for(int i=0; i<n; i++){
            sum1 = sum2 = 0;
            for (int j=0; j<n; j++){
                sum1 += gggg[i][j];
                sum2 += gggg[j][i];
            }
            long tmp = Math.max(sum1, sum2);
            ans = Math.max(tmp, ans);
        }

        sum1 = sum2 = 0;
        for(int i=0; i<n; i++){
            sum1 += gggg[i][i];
            sum2 += gggg[i][n-i-1];
        }
        long tmp = Math.max(sum1, sum2);
        ans = Math.max(tmp, ans);

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