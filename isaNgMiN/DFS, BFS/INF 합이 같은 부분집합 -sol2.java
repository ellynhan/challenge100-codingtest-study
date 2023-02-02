import java.util.*;

class Main{

    static int[] t;
    static int n;
    static int total=0;
    static String ans = "NO";
    static boolean flag = false;

    public static void dfs(int d, int sum){
        if(flag) return;
        if(sum > total/2) return;
        if(d == n){
            if(total-sum == sum){
                ans = "YES";
                flag = true;
            }
        }
        else{
            dfs(d+1, sum+t[d]);
            dfs(d+1, sum);
        }
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
            total += t[i];
        }

        dfs(0, 0);
        System.out.print(ans);

    }
}