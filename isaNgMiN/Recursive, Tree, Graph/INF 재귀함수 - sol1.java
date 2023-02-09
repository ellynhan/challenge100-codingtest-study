// 재귀함수로 1~N 출력

import java.util.*;

class Main{

    public static void recur(int n){
        if(n==1);
        else recur(n-1);
        System.out.print(n + " ");
    }

    public static void sol(int n){
        recur(n);
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        sol(n);
    }
}