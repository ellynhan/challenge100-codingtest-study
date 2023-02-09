import java.util.*;

class Main{

    public static String solution(String s){
        String ans = "";

        String[] ss = s.split(" ");
        for (String x : ss){
            if (x.length() > ans.length()) ans = x;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        System.out.print(solution(s));
    }
}
