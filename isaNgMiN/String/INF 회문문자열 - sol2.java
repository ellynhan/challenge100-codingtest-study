// 앞에서 읽을때랑 뒤에서 읽을때 같은 문자열

// 전처리 대소문자 구분 X -> 어퍼케이스
// 1. 리버싱해서 같은지 비교
// 2. 투포인트로 비교


import java.util.*;

class Main{

    public static String sol(String s){
        s = s.toUpperCase();
        String comp = new StringBuilder(s).reverse().toString();

        if (comp.equals(s)) return "YES";
        else return "NO";

    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }

}