import java.util.*;

class Main{

    public static String solution(String s){
        String ans="";
        char[] cc = s.toCharArray();
        int lt = 0; int rt = s.length()-1;

        while(lt<rt){
            if (!Character.isAlphabetic(cc[lt])) lt++;
            else if(!Character.isAlphabetic(cc[rt])) rt--;
            else {
                char tmp = cc[lt];
                cc[lt] = cc[rt];
                cc[rt] = tmp;
                lt++;
                rt--;
            }
        }

        ans = String.valueOf(cc);
        return ans;
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(solution(s));

    }
}