import java.util.*;

class Main{

    public static String sol(String s){

        s = s.toUpperCase();
        int lt = 0; int rt = s.length()-1;

        while(lt<rt){
            if(s.charAt(lt) != s.charAt(rt)) return "NO";
            else{
                lt++;
                rt--;
            }
        }

        return "YES";
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }

}