// 중복순열
//  1부터 N까지 구슬
//  중복을 허락하여, M번 뽑아, 일렬로 나열(순서까지)

// dfs
//   depth까지
//   depth에서 출력 쏴보리기

import java.util.*;

class Main{

    static int n;
    static int m;
    static int[] t;
    public static void dfs(int d){
        if(d>m) return;
        if(d==m){
            for(int i=0; i<m; i++) {
                System.out.print(t[i] + " ");
            }
            System.out.println();
        }else{
            for(int i=1; i<=n; i++) {
                t[d] = i;
                dfs(d + 1);
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        t = new int[n];

        dfs(0);
    }
}

