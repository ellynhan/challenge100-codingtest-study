// 모든 나열
// N, M, N개의 자연수가 오름차순으로
// 출력순서 오름차순으로 출력

// dfs

import java.util.*;

class Main{

    static int n,m;
    static int[] t;
    static ArrayList<Integer> tans = new ArrayList<>();

    public static void dfs(int d){
        if(m==d){
            for(int x:tans) System.out.print(x + " ");
            System.out.println();
        }else{
            for(int i=0; i<n; i++){
                if(tans.contains(t[i])) continue;
                tans.add(t[i]);
                dfs(d+1);
                tans.remove((Integer)t[i]);
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        t = new int[n];
        for(int i=0;i<n;i++){
            t[i] = sc.nextInt();
        }


        dfs(0);

    }
}