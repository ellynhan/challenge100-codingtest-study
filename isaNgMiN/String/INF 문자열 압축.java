import java.util.*;

class Main{

    public static String sol(String s){
        String ans = "";
        int cnt = 1;
        char c = s.charAt(0);
        s = s + " ";

        for(int i=1; i<s.length(); i++){
            if (s.charAt(i) == c){
                cnt++;
            }
            else {
                ans += c + String.valueOf(cnt);
                cnt = 1;
                c = s.charAt(i);
            }
//            if (i == s.length()-1){
//                ans += c + String.valueOf(cnt);
//            }
        }
        ans = ans.replaceAll("1", "");

        return ans;
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }
}
