// 문자+숫자의 문자열 -> 숫자만 추출하여 순서그대로의 자연수 만들기

// 로직: replaceAll 숫자아닌거 제거 -> 문자를 숫자화


import java.util.*;

class Main{

    public static long sol(String s) {
        long ans = 0;

        for (char x : s.toCharArray()) {
            if (x >= 48 && x < 58) {
                ans = ans * 10 + (x-48);
            }

        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }
}