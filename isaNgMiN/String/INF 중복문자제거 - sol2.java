// 소문자로 된 한개의 문자열
// 중복문자제거 출력


import java.util.*;

class Main{

    public static String solution(String s){
        String ans="";

        for(int i=0; i<s.length(); i++){
            if (s.indexOf(s.charAt(i)) == i) ans+= s.charAt(i);
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(solution(s));

    }

}