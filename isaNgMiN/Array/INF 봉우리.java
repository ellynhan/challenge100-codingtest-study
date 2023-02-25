// 2차원에서 상하좌우보다 큰 중앙의 갯수

// 예외. 가장자리 0으로 초기화 -> 받을때부터 n+2로 받고 해당부분 0으로 초기화

// 로직. 이중for -> 상하좌우 체크 -> 카운팅
//  for 1->n / 1->n: 0초기화까지 가지 않는다

import java.util.*;

class Main{

    public static long sol(int n, long[][] gggg){
        long ans = 0;

        int[] dx = {0,1,0,-1};
        int[] dy = {-1,0,1,0};

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=0; k<4; k++){
                    if(gggg[i+dx[k]][j+dy[k]] >= gggg[i][j]) break;
                    if(k==3) ans+=1;

                }
            }
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] gggg = new long[n+2][n+2];
        for(int i=1; i<n+1; i++) {
            for (int j = 1; j < n + 1; j++) {
                gggg[i][j] = sc.nextLong();
            }
        }

        System.out.print(sol(n,gggg));

    }
}