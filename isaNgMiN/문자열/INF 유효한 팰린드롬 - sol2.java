import java.util.*;

class Main{

    public static String sol(String s){
        s = s.toUpperCase().replaceAll("[^A-Z]","");
        String comp = new StringBuilder(s).reverse().toString();

        if(comp.equals(s)) return "YES";
        else return "NO";

    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        System.out.println(sol(s));
    }
}

