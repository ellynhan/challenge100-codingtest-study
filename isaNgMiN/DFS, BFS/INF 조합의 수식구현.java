// 조합식사용. 조합의 수 출력

// dfs
//   모든것을 거슬러올라와 연산
//   dfs + dfs

import java.util.*;

class Main{

    static int n,r;
    static int[][] cac;

    public static int dfs(int d, int f, int b){
        if(cac[f][b] != 0){
            return cac[f][b];
        }
        else if(b==1){
            return f;
        }
        else if(f == b){
            return 1;
        }else{
            return cac[f][b] = dfs(d+1, f-1, b-1) + dfs(d+1, f-1, b);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        r = sc.nextInt();

        cac = new int[n+1][n+1];

        System.out.print(dfs(0, n, r));

    }
}