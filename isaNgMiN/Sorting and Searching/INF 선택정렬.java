// 선택정렬 선택해서 정렬 선택해서 맨앞으로

// 로직
//  1. 가장작은수 선택
//  2. 정렬안된곳기준 가장 앞으로


import java.util.*;

class Main{

    public static int[] sol(int n, int[] t){

        int idx, tmp;
        for(int i=0; i<n; i++){
            idx = i;
            for(int j=i; j<n; j++) {
                if(t[j] < t[idx]) idx = j;
            }
            tmp = t[i];
            t[i] = t[idx];
            t[idx] = tmp;
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
        for(int x:ans){System.out.print(x + " ");}
    }
}