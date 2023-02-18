import java.util.*;

class Main{

    static int[] check;
    static int n;

    public static void dfs(int d){
        if(d==n+1){
            for(int i=1; i<=n; i++){
                if(check[i] == 1)System.out.print(i + " ");
            }
            System.out.println();
        }
        else{
            check[d] = 1;
            dfs(d+1);
            check[d] = 0;
            dfs(d+1);

        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        check = new int[n+1];

        dfs(1);

    }
}