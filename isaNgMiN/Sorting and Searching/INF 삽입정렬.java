// 삽입하여 정렬

import java.util.*;

class Main{

    public static int[] sol(int n, int[] t){

        for(int i=1; i<n; i++){
            int tmp = t[i], j;
            for(j=i-1; j>=0; j--){
                if(t[j] > tmp) t[j+1] = t[j];
                else break;
            }
            t[j+1] = tmp;
        }
        return t;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }

        int[] ans = sol(n,t);
        for(int x:ans) {System.out.print(x + " ");}
    }
}