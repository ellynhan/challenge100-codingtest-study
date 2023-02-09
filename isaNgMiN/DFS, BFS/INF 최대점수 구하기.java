// 제한시간 M안에 얻을 수 있는 최대점수
// 점수, 시간
// max

// dfs
//  시간넘기면 종료
//  max


import java.util.*;

class Prob{
    int s;
    int t;

    public Prob(int s, int t){
        this.s = s;
        this.t = t;
    }
}

class Main{

    static long m;
    static int n;
    static Prob[] p;
    static long max = 0;


    public static void dfs(int d, int s, int t){
        if(t>m) return;
        if(d==n){
            max = Math.max(max, s);
        }else{
            dfs(d+1,s+p[d].s, t+p[d].t);
            dfs(d+1, s, t);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextLong();
        p = new Prob[n];
        for(int i=0; i<n; i++){
            p[i] = new Prob(sc.nextInt(),sc.nextInt());
        }
        
        dfs(0,0, 0);
        System.out.print(max);

    }
}