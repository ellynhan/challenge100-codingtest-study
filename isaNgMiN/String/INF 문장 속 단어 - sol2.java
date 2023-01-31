import java.util.*;

class Main{

    public static String solution(String s){
        String ans = "";
        String tans = "";
        int idx;

        while((idx = s.indexOf(' ')) != -1){
            tans = s.substring(0,idx);
            if(tans.length() > ans.length()) ans = tans;
            s = s.substring(idx+1);
        }
        if(s.length() > ans.length()) ans = s;

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        System.out.print(solution(s));
    }
}