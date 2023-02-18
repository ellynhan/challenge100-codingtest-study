// 현수 -> 영희: 대문자로 구성된 문자열
// 암호규칙: 알파벳 하나당 * # 조합 7
//  #:1 *:0 이진수
//  이진수를 십진수화한 아스키코드

// 예외 대문자로만 들어옴

// 로직 7개씩 잘라서 #=1 *=0 replace -> 2to10 -> 아스키변환 -> ans

import java.util.*;

class Main{


    public static String sol(int n, String s){
        String ans = "";
        int tans=0;

        for(int i=0; i<s.length(); i+=7){
            for (int j=0; j<7; j++){
                if(s.charAt(i+j) == '#') tans = tans*2 + 1;
                else if(s.charAt(i+j) == '*') tans = tans*2;
            }
            ans += (char)tans;
            tans = 0;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();

        System.out.print(sol(n, s));

    }
}