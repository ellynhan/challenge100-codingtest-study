import java.util.*;

class Main{

    public static String sol(String s){
        int lt = 0; int rt = s.length()-1;
        s = s.toUpperCase();

        while(lt<rt) {
            if (!Character.isAlphabetic(s.charAt(lt))){
                lt ++;
                continue;
            }
            if (!Character.isAlphabetic(s.charAt(rt))){
                rt --;
                continue;
            }
            if(s.charAt(lt) != s.charAt(rt)) return "NO";
            lt++;
            rt--;
        }
        return "YES";
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        System.out.println(sol(s));
    }
}

