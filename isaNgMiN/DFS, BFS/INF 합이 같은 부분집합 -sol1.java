// 집합을 두개의 부분집합으로 나누었을때 합이 같아지는 경우가 있는지의 유무
// 여과없이 둘로 딱 쪼개야함

// 로직
//  DFS. 두개로 나누는 모든 경우우ㅢ수
//  합이 같으면 return 아니면 continue;

import java.util.*;

class Main{

    static int[] t;
    static int[] check;
    static int n;
    static int sum;
    static String ans = "NO";

    public static void dfs(int e){
        if(e == n){
            int tmp1=0;
            int tmp2=0;
            for(int i=0; i<n; i++){
                if(check[i] == 1) tmp1+=t[i];
                else tmp2+=t[i];
            }
            if(tmp1 == tmp2) {
                ans = "YES";
            }
        }
        else{
            check[e] = 1;
            dfs(e+1);
            check[e] = 0;
            dfs(e+1);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = new int[n];
        sum=0;
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
            sum+=t[i];
        }

        check = new int[n];
        dfs(0);
        System.out.print(ans);

    }
}