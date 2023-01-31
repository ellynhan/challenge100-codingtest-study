import java.util.*;

class Main{

    public static long[] sol(int n){
        long[] ans = new long[n];
        ans[0] = 1; ans[1] = 1;

        for(int i = 2; i<n; i++){
            ans[i] = ans[i-2] + ans[i-1];
        }

        return ans;
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long[] ans = sol(n);
        for(int i=0; i<n; i++){
            System.out.print(ans[i] + " ");
        }
    }
}