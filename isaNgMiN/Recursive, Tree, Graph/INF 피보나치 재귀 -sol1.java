// 팩토리얼연산

// 로직
//

import java.util.*;

class Main{

    public static long recur(int n){
        if(n==1 || n==2) {
            return 1;
        }
        else{
            return recur(n-1) + recur(n-2);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();

        for(int i=1; i<=n; i++) {
            System.out.print(recur(i) + " ");
        }
    }
}