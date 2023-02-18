// dfs 부분집합
//  C이상 리턴
//  sum 중 가장 무거운 무게


import java.util.*;


class Main{

    static int c;
    static int n;
    static int[] t;
    static ArrayList<Long> tans = new ArrayList<>();
    static int sum = 0;

    public static void dfs(int d, long sum){
        if(sum > c) return;
        if(d == n){
            tans.add(sum);
        }
        else{
            dfs(d+1, sum+t[d]);
            dfs(d+1, sum);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        c = sc.nextInt();
        n = sc.nextInt();
        t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }
        long max = 0;

        dfs(0, 0);
        for(long e:tans){
            if(e>max) max = e;
        }

        System.out.print(max);

    }
}