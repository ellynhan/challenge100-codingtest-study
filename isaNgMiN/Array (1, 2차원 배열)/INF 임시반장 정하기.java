// row N / column 5
// 같은 column에 같은 값이 있는 row. 의 수가 최대인 row 찾기

// 예외. row index 1~ -> for row: 1~N / column 0~4
// 예외. 같은 column에. 같은 값이 있으면 true, 중복true는 없다

// 로직 for1 기준row 에 대해서
//         for2 비교row가
//              for3 각column 중 같은 값이 있는지

// 예외1. 입력에서 해결
// 예외2. break로 해결

import java.util.*;

class Main{

    public static int sol(int n, long[][] gggg){
        int ans = 1;

        int tans = 0;
        for(int i=1; i<=n; i++){ // 기준 row
            int comp = 0;
            for(int j=1; j<=n; j++){ //비교 row
                if(i==j) continue;
                for(int k=0; k<5; k++){
                    if(gggg[i][k]==gggg[j][k]) {
                        comp+=1;
                        break;
                    }
                }
            }
            if(comp > tans){
                tans = comp;
                ans = i;
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] gggg = new long[n+1][5];
        for(int i=1; i<n+1; i++){
            for (int j=0; j<5; j++){
                gggg[i][j] = sc.nextLong();
            }
        }

        System.out.print(sol(n,gggg));
    }
}