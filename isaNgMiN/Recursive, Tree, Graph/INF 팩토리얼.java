// 팩토리얼연산

// 로직
//

import java.util.*;

class Main{

    public static long recur(int n){
        if(n==1) return 1;
        else{
            return n*recur(n-1);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();

        System.out.print(recur(n));
    }
}