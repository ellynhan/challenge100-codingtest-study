// 이진수 출력 10진수 -> 2진수 / 단, 재귀로

// 로직
//  나누기 2

import java.util.*;

class Main{

    public static void recur(int n){
        if(n == 0) return;
        else{
            recur(n/2);
            System.out.print(n%2);

        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();

        recur(n);
    }
}