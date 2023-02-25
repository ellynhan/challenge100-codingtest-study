// 버블정렬 -> 버블처럼 바로 옆을 비교하면서 가장 뒤부터 쭉쭉 채워나감

import java.util.*;

class Main{

    public static int[] sol(int n, int[] t){
        int tmp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
               if(t[j] > t[j+1]){
                    tmp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = tmp;
               }
            }
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

        int[] ans = sol(n, t);
        for(int x:ans){System.out.print(x + " ");}


    }
}