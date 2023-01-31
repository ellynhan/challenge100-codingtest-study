import java.util.*;

class Main{

    public static void sol(int n){
        int a = 1; int b = 1;
        System.out.print(a + " " + b + " ");

        int c;
        for(int i=2; i<n; i++){
            c = a+b;
            System.out.print(c + " ");
            a = b;
            b = c;

        }

    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        sol(n);
    }
}