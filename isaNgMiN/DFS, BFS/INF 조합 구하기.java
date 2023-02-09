// 1부터 N까지 번호가 적힌 -> M개를 뽑는 모든 경우의수

// dfs
//  겹치면 continue

import java.util.*;

class Main{

    static int n;
    static int m;
    static ArrayList<Integer> a = new ArrayList<>();
    public static void dfs(int d, int st){
        if(d==m){
            for(int x:a) System.out.print(x + " ");
            System.out.println();
        }else{
            for(int i=st; i<=n; i++) {
                a.add(i);
                dfs(d+1, i+1);
                a.remove((Integer)i);
            }
        }

    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        dfs(0, 1);
    }
}
